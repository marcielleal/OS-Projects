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

    for(int i=0;i<tab;++i)
    	if(i+1==tab)
		std::cout<<".  |-";
	else std::cout<<".  ";
    std::cout<<pid<<"_\n";

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

	if(argc<2){
		std::cout<<"ARGUMENTOS INVALIDOS"<<std::endl;
		return -1;
	}
	saidaJson.open((std::string(argv[1])+std::string(".json")),std::ifstream::out);
	if(saidaJson.is_open()){
		saidaJson<<getJson(argv[1],0);
		saidaJson.close();
	}else std::cout<<"ERRO AO ABRIR ARQUIVO"<<std::endl;

	std::string retCmd=callForProc();

	std::cout<<"Total number of processes: "<<getNumProc(retCmd)<<std::endl;
	std::cout<<"Processes per user: \n"<<retCmd<<std::endl;
	
	return 0;
}
