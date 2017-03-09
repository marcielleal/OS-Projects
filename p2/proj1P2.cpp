#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <cstring>
#define DIRECTORY "/proc"


bool isIgnoredDir(char* dir){
	if(strcmp(dir,".") || strcmp(dir,"..") || strcmp(dir,".git"))
		return true;
	return false;
}



int getPPid(DIR *dp, int id){
	
	dirent *d;
	int ppidLine=5;
	std::ifstream file;
	char buff[100],sid[100];
	int PPid,Pid;
	bool finded=false;
	
	sprintf(sid,"%d",id);

	while((d = readdir(dp)) != NULL && !finded){	
		if((d->d_type==DT_DIR && !strcmp(d->d_name,sid))){
			std::string fileName(d->d_name);
			fileName= std::string(DIRECTORY)+"/"+fileName+"/status";
			file.open(fileName.c_str(),std::ifstream::in);
			std::cout<<fileName<<"\n\n";
			if(file.is_open()){
				for(int i=0;i<ppidLine;++i)
					file.getline(buff,100);
				
				file.getline(buff,100);
				std::cout<<buff<<"\n\n";

				std::cout<<PPid<<"\n\n";
				sscanf("%d",buff,&PPid);
				std::cout<<PPid<<"\n\n";
				finded=true;
			}else return -2;
		}
	}
	if(!finded)
		return -1;
	return PPid;
}


int main(int argc, char *argv[])
{
	DIR *dp;

	if((dp = opendir(DIRECTORY)) != NULL){
		std::cout<<getPPid(dp,156)<<std::endl;
	}else{ 
		std::cout<<"ERROR"<<std::endl;
		return -1;
	}
	return 0;
}
