命名:
    自注释性，长度适中(3, 20)
    文件名: 小写，头文件.h 实现文件.cpp 例如：log_buffer.h
    类型名: 开头大写，骆驼命名，例如: 
        class DataReader{...}
        struct DataReader{...}
        enum Color{...}
    变量名：全小写，用下划线连接各个token;
        成员变量以m_开头，如：m_channel;
        临时变量要求表达性高，如：ret_errorcode;
