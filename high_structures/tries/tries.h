// =====================================================================================
//
//       Filename:  tries.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年03月14日 22时51分14秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#ifndef _TRIES_H_
#define _TRIES_H_

#include <iostream>
#include <tuple>
#include <vector>
#include <string>

typedef struct TriesNode
{
    std::tuple<char, std::vector<struct TriesNode*>, std::size_t>node;
}TriesNode;


class tries
{
    public:
        tries() = default;
        ~tries() { }
        bool t_Insert(std::string &s);
        bool t_Delete(std::string &s);
        bool t_search(std::string &s);

    private:
        TriesNode m_root;    //根节点
};

bool
tries::t_Insert(std::string &s)
{
    bool flag = false;
    auto iter = s.begin();
    std::vector<struct TriesNode*>&tmp = std::get<1>(m_root.node);
    struct TriesNode *q = &m_root;
    for(; iter != s.end(); ++iter)
    {
        auto p = tmp.begin();
        for(; p != tmp.end(); ++p)
        {
            if(std::get<0>((*p)->node) == *iter)
            {
                /* 引用计数加1 */
                std::get<2>((*p)->node)++;
                flag = true;
                break;
            }
        }
        /* 找到对应的字母 */
        if(flag == true)
        {
            tmp = std::get<1>((*p)->node);
            q = *p;
            flag = false;
        }
        /* 已经到尽头 */
        else
        {
            break;
        }
    }
    for(; iter != s.end(); ++iter)
    {
        struct TriesNode tn;
        tn.node = std::make_tuple(*iter, std::vector<struct TriesNode*>(), 1);
        struct TriesNode *ptr = &tn;
        std::get<1>(q->node).push_back(ptr);
        auto q = std::get<1>(tn.node);
    }
    return true;
}

bool
tries::t_Delete(std::string &s)
{
    std::vector<struct TriesNode*>&tmp = std::get<1>(m_root.node);
    if(t_search(s) == true)
    {
        for(auto iter = s.begin(); iter != s.end(); ++iter)
        {
            auto p = tmp.begin();
            for(; p != tmp.end(); ++p)
            {
                if(std::get<0>((*p)->node) == *iter)
                {
                    if(--std::get<2>((*p)->node) == 0)
                    {
                        //清除后面的元素
                        tmp.erase(p);
                    }
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool
tries::t_search(std::string &s)
{
    auto iter = s.begin();
    struct TriesNode *q = &m_root;
    std::vector<struct TriesNode*>&tmp = std::get<1>(m_root.node);
    for(; iter != s.end(); ++iter)
    {
        auto p = tmp.begin();
        for(; p != tmp.end(); ++p)
        {
            if(std::get<0>((*p)->node) == *iter)
            {
                break;
            }
            else
            {
                return false;
            }
            tmp = std::get<1>((*p)->node);
        }
    }
    return true;
}


#endif
