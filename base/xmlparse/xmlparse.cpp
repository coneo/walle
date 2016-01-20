#include "xmlparse.h"

using namespace walle;
using namespace base;
using namespace tinyxml2;

XmlParseDoc::XmlParseDoc(const char* filename)
{
    m_doc = std::make_shared<XMLDocument>();
    m_doc->LoadFile(filename);
}

XmlParseNode XmlParseDoc::getRoot()
{
    if (m_doc)
    {
        XMLElement* ele = m_doc->RootElement();
        XmlParseNode node(ele);
        return node;
    }

    return XmlParseNode();
}

XmlParseNode::XmlParseNode(XMLElement* ele)
    : m_ele(ele)
{
}

XmlParseNode XmlParseNode::getChild(const char* name)
{
    if (m_ele != nullptr)
    {
        XMLElement* ele = m_ele->FirstChildElement(name);
        XmlParseNode node(ele);
        return node;
    }

    return XmlParseNode();
}

std::string XmlParseNode::getText()
{
    if (m_ele != nullptr)
    {
        return m_ele->GetText();
    }
    return "";
}
