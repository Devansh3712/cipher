/**
    File Input/Output.
    @file fileio.cpp
    @author Devansh Singh
    @brief Read and write to text files.
    @date 06/03/2022
*/

#include <fstream>
#include <sstream>
#include "fileio.hpp"

/**
    Constructor for the FileIO class.
    @param path_to_file Path of the file to read/write.
*/
FileIO::FileIO(std::string path_to_file){
    file_path = path_to_file;
}

/**
    Read the contents of a file.
    @returns File content.
*/
std::string FileIO::read(){
    std::ifstream infile;
    infile.open(file_path);
    std::stringstream stream;
    stream << infile.rdbuf();
    infile.close();
    return stream.str();
}

/**
    Write content to the file.
    @returns True if content is written else false.
*/
bool FileIO::write(std::string data){
    try{
        std::ofstream infile;
        infile.open(file_path);
        infile << data;
        infile.close();
        return true;
    }catch(...){
        return false;
    }
}