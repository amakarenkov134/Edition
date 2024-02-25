## Edition


``` c++
class Edition
{
protected:
    char name[90];
    char autor[90];
    int year;

public:
    Edition();
    ~Edition();
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void input_from_file(std::ifstream& fin) = 0;
    bool compare_name(char* snp);
    bool compare_fio(char* snp);
    bool sorting(Edition* e);
};


```

## Allowance


``` c++ 
class Allowance :
    public Edition
{
    char link[90];

public:
    void input();
    void input_from_file(ifstream& fin);
    void output();
    bool operator >(Allowance d);
};

```


## Article


``` c++
class Article :
    public Edition
{
    char magazineName[90];
    int number;
    int first_page;
    int last_page;

public:
    void input();
    void input_from_file(ifstream& fin);
    void output();
    bool operator >(Article d);
};

```

## Book 

``` c++ 
class Book :
    public Edition
{
    int pages;

public:
    void input();
    void input_from_file(ifstream& fin);
    void output();
    bool operator >(Book d);
};
```
