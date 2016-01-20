#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;
using namespace std;

int main(int argc, char** argv)
{
    XMLDocument doc;
    doc.LoadFile("test.xml");

    cout << "errorcode:" << doc.ErrorID() << endl;

    const XMLElement* root = doc.RootElement();
    if (!root )
    {
        cout << "errcode:" << XML_ERROR_FILE_READ_ERROR << endl;
        return 0;
    }

    for (const XMLElement* ele = root->FirstChildElement("Person");
         ele; 
         ele = ele->NextSiblingElement("Person"))
    {
        int id = 0;
        float gogo = 0;
        ele->QueryIntAttribute("ID", &id);
        ele->QueryFloatAttribute("GOGO", &gogo);

        cout << "nodename:" << ele->Name() << " id:" << id << " gogo:" << gogo << endl;
    }

    cout << "wocao:" << root->FirstChildElement("WOCAO")->Attribute("str") << endl;
    cout << "haha:" << root->FirstChildElement("haha")->GetText() << endl;
}
