#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
typedef struct LNode
{
    int lineNum;
    LNode *next;
} LNode;
typedef struct WTL
{
    string word;
    int times;
    LNode *lines;
} WTL;

void initializeWTL(WTL &wtl, const std::string &word)
{
    wtl.word = word;
    wtl.lines = nullptr;
    wtl.times = 0;
}

// 创建下一个节点
void createNextNode(WTL &wtl, int lineNum)
{
    LNode *newNode = new LNode;
    newNode->lineNum = lineNum;
    newNode->next = nullptr;

    if (wtl.lines == nullptr)
    {
        wtl.lines = newNode;
    }
    else
    {
        LNode *currNode = wtl.lines;
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

std::vector<int> computeNext(const std::string &pattern)
{
    int len = pattern.length();
    std::vector<int> next(len);

    int i = 0, j = -1;
    next[0] = -1;

    while (i < len - 1)
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }

    return next;
}

int exist(std::string word, std::string line)
{
    int i = 0;
    int j = 0;
    int count = 0;
    std::vector<int> next;
    next = computeNext(word);
    while (i == -1 || (i <= word.length() && j <= line.length()))
    {
        if (i == -1 || word[i] == line[j])
        {
            i++;
            j++;
        }
        else
        {
            i = next[i];
        }
        if (i == word.length())
            count++;
        if (j == line.length())
            return count;
    }

    return 0;
}

int main()
{
    cout << "Please enter words need to be searched in one line" << endl;
    std::string line;
    std::getline(std::cin, line); // 从输入读取一行

    std::istringstream iss(line);   // 创建一个istringstream对象，以处理这一行
    std::vector<std::string> words; // 创建一个字符串向量来存储单词
    std::vector<WTL> results;
    std::string word;
    WTL newwtl;
    while (iss >> word)
    {                          // 从istringstream对象中读取单词，直到遇到行尾
        words.push_back(word); // 将读取到的单词添加到字符串向量中
        initializeWTL(newwtl, word);
        results.push_back(newwtl);
    }

    std::string path;
    std::cout << "Please enter the path of the file:" << endl;
    std::cin >> path;
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream file(path);
    int nline = 1;  // 行号
    int numOfWords; // 词数
    if (file.is_open())
    { // 如果文件打开成功
        std::string line;
        while (std::getline(file, line))
        {

            for (WTL &wtl : results)
            {
                numOfWords = exist(wtl.word, line);
                if (numOfWords > 0)
                {
                    createNextNode(wtl, nline);
                    wtl.times += numOfWords;
                }
            }
            nline++;
        }
        file.close(); // 关闭文件
    }
    else
    {
        std::cerr << "Failed to open file." << ::endl;
    }

    for (WTL &wtl : results)
    {
        if (wtl.times > 0)
        {
            std::cout << wtl.word << " occurs " << wtl.times << " times in lines ";
            for (LNode *p = wtl.lines; p != nullptr; p = p->next)
            {
                std::cout << p->lineNum << " ";
            }
            cout << std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "it cost " << duration.count() << " seconds" << std::endl;

    return 0;
}