#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
int main()
{
typedef map<string,int>mapType;
mapType populationMap;
populationMap.insert(pair<string,int>("MAHARASHTRA",1339));
populationMap.insert(pair<string,int>("GUJRAT",1187));
populationMap.insert(mapType::value_type("BIHAR",310));
populationMap.insert(mapType::value_type("GOA",234));
populationMap.insert(make_pair("MP",170));
populationMap.insert(make_pair("UP",193));
mapType::iterator iter=--populationMap.end();
populationMap.erase(iter);
cout<<"Size Of PopulationMap:"<<populationMap.size()<<'\n';
for(iter=populationMap.begin();iter!=populationMap.end();++iter)
{
cout<<iter->first<<":"
<<iter->second<<" Million\n";
}
string State;
cout<<"Enter the State with Population: \n";
cin>>State;
iter=populationMap.find(State);
if(iter!=populationMap.end())
cout<<State<<"s populations is"<<iter->second<<"million\n";
else
cout<<"Key Is Not In PopulationMap"<<'\n';
populationMap.clear();
}
