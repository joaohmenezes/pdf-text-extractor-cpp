/*
Joao Henrique de Menezes Pereira Santos 
*/


#include <iostream>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-page-renderer.h>
#include <poppler/cpp/poppler-font.h>
#include <poppler/cpp/poppler-global.h>
#include <dirent.h>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

vector<string> listaArquivo(const string& diretorio) {
    vector<string> arquivos;
    DIR* dir = opendir(diretorio.c_str());
    if (dir != nullptr) {
        dirent* entrada;
        while ((entrada = readdir(dir)) != nullptr) {
            if (entrada->d_type == DT_REG && strcmp(entrada->d_name, ".") != 0 && strcmp(entrada->d_name, "..") != 0) {
                arquivos.push_back(entrada->d_name);
            }
        }
        closedir(dir);
    }
    else {
        cout << "Erro ao abrir diretorio: " << diretorio << endl;
    }
    return arquivos;
}

int main() {
    string diretorio;
    cout << "Digite o caminho para o diretorio onde estao os arquivos PDF: ";
    getline(cin, diretorio);
    
    vector<string> files = listaArquivo(diretorio);

    int numArquivosProcessados = 0;
    unordered_map<char, int> contaPrimeiraLetra;

    for (const auto& nomeDoArquivo : files) {
        numArquivosProcessados++;

        poppler::document* doc = poppler::document::load_from_file(diretorio + "/" + nomeDoArquivo);
        if (doc) {
            int qtdPalavras = 0;
            for (int i = 0; i < doc->pages(); ++i) {
                poppler::page* pagina = doc->create_page(i);
                if (pagina) {
                    poppler::ustring renderer;
                    renderer = pagina->text();
                    auto pageRenderResult = renderer.to_utf8();
                    char letraAnterior = ' ';
                    for (char& caractere : pageRenderResult) {
                        int valorAscii = static_cast<int>(caractere);
                        if (valorAscii >= 0 && valorAscii <= 255 && isalpha(caractere) && letraAnterior == ' ') {
                            contaPrimeiraLetra[toupper(caractere)]++;
                            qtdPalavras++;
                        }
                        letraAnterior = caractere;
                    }
                }
            }
           
            cout << "Numero de palavras processadas de " << nomeDoArquivo << ": " << qtdPalavras << endl;
            delete doc;
        }
        else {
            cout << "Erro ao carregar o arquivo: " << nomeDoArquivo << endl;
        }
    }
    cout << endl;
    cout << "Numero de arquivos processados: " << numArquivosProcessados << endl << endl;
    for (char letra = 'A'; letra <= 'Z'; ++letra) {
        cout << "_Letra " << letra << "_ : " << contaPrimeiraLetra[letra] << endl;
    }

    return 0;
}
