#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>

#define PROGRAM_NAME "fastat"

using namespace std;

int fastat_help(void);
int fasta_stat(const string& filename);

int main(int argc, char **argv)
{
    if (argc < 2 ) return fastat_help();

    string sub_cmd = argv[1];

    if (sub_cmd =="-h" || sub_cmd=="--help")
        return fastat_help();

    else
        return fasta_stat(sub_cmd);

    return 0;

}

int fastat_help(void)
{

    cout<< PROGRAM_NAME <<": tools to extract statistical data from a fasta file.\n";
    cout<<"usage:   fastat <file>"<<endl<<endl;
    cout<<endl;
    cout<<" file            "<<"Any fasta file.\n";
    cout<<" --help          "<<"Print this help menu.\n";

    return 0;

}

int fasta_stat(const string& filename)
{

    ifstream infile(filename.c_str());
    if (!infile.good())
        cout<<"Error.. Cannot read file"<<endl;
    else
    {
        uint64_t total = 0;
        string line;
        std::map<char, uint64_t > bases = {{'A',0},{'C',0},{'G',0},{'T',0},{'N',0}};


        if (infile.is_open())
        {

            while (infile.good()) {
                getline(infile, line);
                if (line.length() > 0)
                {
                    if ( line.at(0) != '>') {

                        for (auto letter : line)
                        {
                            letter = toupper(letter);
                            bases[letter]+=1;
                            total++;
                        }
                    }
                }
            }

            infile.close();
            cout<<"total\t"<<total<<endl;
            for (auto& item: bases)
            {
                if (item.second != 0)
                    cout<<item.first<<"\t"<<item.second<<"\t"<<double(item.second)/double(total)<<endl;


            }





        }


    }


}



