#include <cstdio>
#include <iostream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "json.hpp"
#include <queue>

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

json getJson(std::string pid){
    json saida;
    std::istringstream f (exec((std::string("pgrep -P ")+pid).c_str()));
    std::string line;

    while (std::getline(f,line)){
	saida[pid][line]=getJson(line)[line];
    }
    if(saida==nullptr)
	saida[pid]=nullptr;
    return saida;
}



int main(int argc,char **argv){
	json saida;    
	
	if(argc<2){
		std::cout<<"ARGUMENTOS INVALIDOS"<<std::endl;
		return -1;
	}
	std::cout<<getJson(argv[1])<<std::endl;

	return 0;
}
