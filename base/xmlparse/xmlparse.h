/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2016-01-17 20:51 +0800
 *
 * Description: 封装xml解析接口
 */

#ifndef WATER_BASE_XMLPARSE_H
#define WATER_BASE_XMLPARSE_H

#include "tinyxml2.h"
#include <string>
#include <memory>

namespace walle{
namespace base{

class XmlParseNode;

class XmlParseDoc
{
    public:
        XmlParseDoc(const char* filename);
        XmlParseNode getRoot();

    private:
        std::shared_ptr<tinyxml2::XMLDocument> m_doc;
};

class XmlParseNode
{
    public:
        XmlParseNode() = default;
        XmlParseNode(tinyxml2::XMLElement* ele);

    public:
        XmlParseNode getChild(const char* name);

        operator bool() const
        {
            return (m_ele != nullptr);
        }

        XmlParseNode& operator++()
        {
            if (m_ele != nullptr)
            {
                m_ele = m_ele->NextSiblingElement(m_ele->Name());
            }
            return *this;
        }

        template <typename T>
        T getAttr(const char* name)
        {
            T ret;
            getAttrByType(name, &ret);
            return ret;
        }

        std::string getText();

    private:

        void getAttrByType(const char* name, int* ret)
        {
            if (m_ele != nullptr)
                m_ele->QueryIntAttribute(name, ret);
        }

        void getAttrByType(const char* name, unsigned int* ret)
        {
            if (m_ele != nullptr)
                m_ele->QueryUnsignedAttribute(name, ret);
        }

        void getAttrByType(const char* name, bool* ret)
        {
            if (m_ele != nullptr)
                m_ele->QueryBoolAttribute(name, ret);
        }

        void getAttrByType(const char* name, float* ret)
        {
            if (m_ele != nullptr)
                m_ele->QueryFloatAttribute(name, ret);
        }

        void getAttrByType(const char* name, double* ret)
        {
            if (m_ele != nullptr)
                m_ele->QueryDoubleAttribute(name, ret);
        }

        void getAttrByType(const char* name, std::string* ret)
        {
            if (m_ele != nullptr)
                *ret = m_ele->Attribute(name);
        }

    private:

        tinyxml2::XMLElement* m_ele = nullptr;
};

}}

#endif
