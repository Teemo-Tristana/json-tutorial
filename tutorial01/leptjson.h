
/**
 * 一般会在头文件中进行 #include ，但是头文件中也可能会有其他头文间，为了避免重复声明，一般用 宏 来进行include防范(include guard)
 *  宏 的名字必须唯一 ，后缀以 _H__ 作为后缀
*/
 
#ifndef LEPTJSOH_H__
#define LEPTJSOH_H__


//类型枚举: c 语言没有 C++ 的命名空间，因此，一般是使用项目的简写作为标识符的前缀， 通常枚举值用全大写，类型和函数名则用小写
typedef enum {LEPT_NULL, LEPT_FALSE, LEPT_TURE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT} lept_type;


typedef struct 
{
    /* data */
    lept_type type;
}lept_value;


enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

// 解析 JSON
int lept_parse(lept_value* v, const char* json);

// 获取类型
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
