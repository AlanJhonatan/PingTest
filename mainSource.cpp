#include <bits/stdc++.h>
#include <stdlib.h>
#include <chrono>
#include <ctime> 
#include <windows.h>
#include <fstream>

using namespace std;

void PrintaEnd(){
	// ----- NADA IMPORTANTE
	cout << "... PRESSIONE CTRL+C PARA FINALIZAR O PROCESSO ..."<< endl;
	cout << endl;
	// --------------------
}

void PrintaLog(string ip, int q){
	cout << "[ " << ip << " ] " << "LOGS GERADOS ATE O MOMENTO: " << q << endl;
}


int main (){
	
	PrintaEnd();
	int logs = 0;
	// -- Start do INPUT DO IP
	string ipAdress;
	cout << "Informe o Endereco IP:" << endl;
	cout << ">";
	cin >> ipAdress;
	// -- end INPUT DO IP
	
	while(1){
	// -- Start PING 
	string comando = "ping -s 1 " + ipAdress + " > \pingdata.txt";
	system(comando.c_str());
	// -- End  PING
	
	string full_txt; // ! Important !
	string txt; 	 // ! Important !
	
	int count = 0;	
	string temp;

	ifstream input_all ("pinglog.txt");
	while(getline(input_all,temp)){
		full_txt += temp + '\n';
	}
	input_all.close();
	
	
	ifstream input_log ("pingdata.txt");
	while(getline(input_log,temp)){
		if(count >= 11)
			txt += temp + '\n'; 
		count++;
	}
	input_log.close();
	
	logs++;
	system("cls");
	PrintaEnd();
	PrintaLog(ipAdress,logs);
	
	temp = "";
	count = 0;
	
	ofstream output_log;
	output_log.open("pinglog.txt");
	
	//- Start Time
	auto end = chrono::system_clock::now();
	time_t end_time = chrono::system_clock::to_time_t(end);
	//-- End Time
	// print ctime(&end_time).
	output_log << full_txt;
	output_log << "\n";
	output_log << ctime(&end_time);
	output_log << txt;
	output_log << "\n";
	output_log.close();
}
	return 0;
}
