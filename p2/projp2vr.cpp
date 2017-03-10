#include <cstdio>
#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "json.hpp"
#include <queue>
#include <fstream>
#include <unistd.h>

using json = nlohmann::json;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}

json getJson(std::string pid,int tab){
    json saida;
    std::istringstream f (exec((std::string("pgrep -P ")+pid).c_str()));
    std::string line;
    while (std::getline(f,line)){
	saida[pid][line]=getJson(line,tab+1)[line];
    }
    if(saida==nullptr)
	saida[pid]=nullptr;
    return saida;
}

std::string callForProc(){
	return exec("ps hax -o user | sort | uniq -c");
}

int getNumProc(std::string retCmd){
	std::istringstream f(retCmd);
	std::string line;
	int temp,total=0;
	while (std::getline(f,line)){
		sscanf(line.c_str(),"%d",&temp);
		total+=temp;
	}

	return total;
}


int main(int argc,char **argv){
	json saida;    
	std::ofstream saidaJson;
	int time;

	if(argc<3){
		std::cout<<"Usage: " << argv[0] << " <PID of Process> <Time of Refresh>\n" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	sscanf(argv[2],"%d",&time);
	if( time<=0 ){
		std::cout<<"Time doesn't run backwards"<<std::endl;
		exit(EXIT_FAILURE);
	}

	while(1){
		std::string retCmd = callForProc();

		std::cout << "Total number of processes: " << getNumProc(retCmd) << std::endl;
		std::cout << "Processes per user: \n"<<retCmd<<std::endl;
        std::cout << std::endl << std::endl;
        sleep(time);
	}
	return 0;
}
