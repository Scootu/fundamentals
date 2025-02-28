#include <bits/stdc++.h>
using namespace std;

class ConfigurationManger
{
private:
    string configuration_path;
    static vector<string> servers_ips;
    static string aws_service_url;
    // Other heavy data
    static bool is_loaded;

public:
    ConfigurationManger(string configuration_path) : configuration_path(configuration_path)
    {
    }
    static void Load()
    {
        if (is_loaded)
            return;
        // some heavy load
        cout << "Lazy loading\n";
        servers_ips.push_back("10.20.30.40");
        servers_ips.push_back("10.20.30.41");
        servers_ips.push_back("10.20.30.42");
        aws_service_url = "https://dynamodb.us-west-2.amazonaws.com";
        is_loaded = true;
    }
    string GetAwsServiceUrl()
    {
        Load();
        return aws_service_url;
    }
};
// Static member initialization
vector<string> ConfigurationManger::servers_ips;
string ConfigurationManger::aws_service_url;
bool ConfigurationManger::is_loaded = false;

void f1()
{
    ConfigurationManger mgr("/home/moustafa/conf_info.txt");
    cout << mgr.GetAwsServiceUrl() << "\n";
}

void f2()
{
    ConfigurationManger mgr("/home/moustafa/conf_info.txt");
    cout << mgr.GetAwsServiceUrl() << "\n";
}
void f3()
{
    ConfigurationManger mgr("/home/moustafa/conf_info.txt");
    cout << mgr.GetAwsServiceUrl() << "\n";
}
int main()
{
    f1();
    f2();
    f3();
    return 0;
}