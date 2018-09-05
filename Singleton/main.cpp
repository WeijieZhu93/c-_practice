//
// Created by apple on 2018/8/31.
//

#ifndef XUEXI_SINGLETON_H
#define XUEXI_SINGLETON_H

class Singleton
{
public:
    static Singleton& Instance()
    {
        //使用local static对象，避免了初始化non-local static对象顺序的不确定性。
        static Singleton instance;
        return instance;
    }
private:
    Singleton(){};
    ~Singleton(){};
    Singleton(const Singleton&){};
    Singleton& operator=(const Singleton&){};
};

#endif //XUEXI_SINGLETON_H

