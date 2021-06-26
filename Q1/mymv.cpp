#include<iostream>
#include<string.h>
#include<cstdio>
#include <sys/stat.h>                                                                                   //For importing stat structure to create function to check type of file to be moved.

std::string getFileName(std::string filePath, bool withExtension = true, char seperator = '/')          //This function is to get the file name other than it's path so that when moved, it's name is retreaved.
{
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);
    if(sepPos != std::string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension || dotPos != std::string::npos ? 1 : dotPos) );
    }
    return "";
}

int is_regular_file(const char *path)                                                                   //This function is to check if the file to be moved contains an extention or not.
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int main(int argc, char* argv[]){
    if(argc>=3){
        for (int i=1;i<argc-1;i++){
            
            bool isF=is_regular_file(argv[i]);

            std::string s=argv[i];
            if(isF){
                
                s=getFileName(s);                                                             
            }
            else{
                s=getFileName(s,false);
                
            }
            std::string path=strcat(argv[argc-1],"/");                                                  //
            path.append(s);                                                                             //These 2 lines forms the absolute new path for the file to be moved by => destination + "/" + filename(retreaved from original file using function)
            int n = path.length();                                                                      //
            // printf("%s",path.c_str());                                                               //
            // printf("%s",s.c_str());                                                                  //
            char dest[n+1];                                                                             //
            strcpy(dest, path.c_str());                                                                 //These lines are to convert the path name from string to a array of char as remove function only accept array of character and not string.
            // printf("%s",dest);                                                                       //
            rename(argv[i],dest);                                                                       //
        }
    }
    else{
        printf("More Arguments Expected");
    }
}