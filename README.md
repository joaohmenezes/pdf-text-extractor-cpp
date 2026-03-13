📄 PDF Text Extractor \& Frequency Analyzer



📌 About the Project

This project is a C++ algorithm designed to read an entire directory containing PDF documents, extract their text content, and perform a detailed lexical analysis. 



\*\*Academic Context:\*\* Practical Project #1 developed for the Data Structures and Algorithms II (ECOI2206) course at the Federal University of Itajubá (UNIFEI)



⚙️ How it Works \& Data Structures

The core logic of the program relies on efficient file handling and robust data structures:



\* \*\*Directory Parsing:\*\* Utilizes the `dirent` library to map and store all filenames from a specified directory into a dynamic `std::vector` of strings.

\* \*\*PDF Processing:\*\* Employs the \*\*Poppler\*\* open-source library to open, read, and extract raw text strings from every page of the targeted PDF files.

\* \*\*Frequency Mapping (Hash Map):\*\* The core data structure used is `std::unordered\_map` (Hash Map). It maps the letters of the alphabet (Keys) to the number of times a word starts with that specific letter (Values) across all documents.



📊 Post-Processing Report

After parsing all files in the directory, the system generates a terminal report detailing:

1\. The total number of processed files.

2\. The total word count for each individual PDF file.

3\. The absolute frequency of words starting with each letter of the alphabet (from A to Z).



🛠️ Technologies \& Dependencies

\* \*\*C++11 or higher\*\*

\* \*\*Poppler (via vcpkg/MSBuild):\*\* Core library for PDF manipulation.

\* \*\*Dirent:\*\* Library for reading directory structures.

