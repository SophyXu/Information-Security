#include <string>  
#include <iostream>  
using namespace std;
  
class Math
{  
private:      
    int len, num[1000];   
public:  
    Math(); 
    Math(string &str); 
    ~Math(){}   
    int getSize(){return len;}   
    Math operator+(Math &);  
    Math operator-(Math &);  
    Math operator*(Math &);  
    Math operator/(Math &);  
    Math operator%(Math &);   
    Math operator/(int x);     
    Math getPow(int t, Math &); 
    Math getPow(Math &, Math &);  
    Math getPow10(int t);   
    bool operator>=(Math &);    
    bool isOdd();  
    bool isOne();  
    void clear();  
    void print();  
};  
Math::Math()
{
    int i;
    len = 1;  
    for(i=0;i<1000;i++)
        num[i] = 0; 
}   
Math::Math(string &str)
{  
    int i;
    len = 1;  
    for(i=0;i<1000;i++)
        num[i] = 0;  
    len = str.length();  
    for(i=len-1;i>=0;i--)  
        num[i] = str[len-i-1]-48;          
}     
Math Math::operator+(Math &other)
{   
    int i;
    Math result;  
    if(len>other.len)
        result.len = len;
    else 
        result.len = other.len;  
    for(i=0;i<result.len;i++)  
        result.num[i] = num[i]+other.num[i];  
    for(i=0;i<result.len;i++)  
        if (result.num[i]>9)
        {  
            result.num[i+1] += result.num[i]/10;  
            result.num[i] %= 10; 
            if(i==result.len-1)
                result.len++; 
        }  
    for(i=result.len-1;i>0;i--)
    {
        if(result.num[i]!=0)
            break;
        result.len--;
    }
    return result;  
}    
Math Math::operator-(Math &other)
{   
    int i;
    Math result = *this;       
    for(i=0;i<other.len;i++)  
        result.num[i] = num[i]-other.num[i];  
    for(i=0;i<result.len;i++)  
        if(result.num[i]<0)
        {  
            result.num[i] += 10;  
            result.num[i+1]--;  
        }   
    for(i=result.len-1;i>0;i--)
    {
        if(result.num[i]!=0)
            break;
        result.len--;
    }  
    return result;  
}   
Math Math::operator*(Math &other)
{    
    int i, j;
    Math result;    
    result.len = len+other.len-1;  
    for(i=0;i<len;i++)
    {  
        for(j=0;j<other.len;j++)
        {  
            result.num[i+j] += num[i]*other.num[j];  
            if (result.num[i+j]>9)
            {  
                result.num[i+j+1] += result.num[i+j]/10;  
                result.num[i+j] %= 10;  
            }  
        }
    }  
    if(result.num[result.len]>0)  
        result.len++;          
    return result;  
}    
Math Math::operator/(Math &other)
{  
    int i, t;
    Math result, now = *this, tmp;           
    if(len<other.len)  
        return result;            
    t = now.len-other.len;  
    while(now>=other)
    {  
        tmp = other.getPow10(t);  
        while(now>=tmp)
        {  
            now = now-tmp;  
            result.num[t]++;  
        }  
        t--;  
    }   
    result.len = len-other.len+1;  
    for(i=result.len-1;i>0;i--)
    {
        if(result.num[i]!=0)
            break;
        result.len--;
    }   
    return result;  
}    
Math Math::operator/(int other)
{    
    int i, tmp = 0;
    Math result;   
    for(i=len-1;i>=0;i--)
    {  
        tmp = tmp*10+num[i];  
        result.num[i] = tmp/other;  
        tmp %= other;  
    }  
    result.len = len;  
    for(i=result.len-1;i>0;i--)
    {
        if(result.num[i]!=0)
            break;
        result.len--;
    }   
    return result;  
}  
Math Math::operator%(Math &other)
{    
    Math t = *this / other * other;        
    return *this - t;   
}   
Math Math::getPow(int t, Math &after)
{      
    Math temp, result;
    if(t == 1)  
        return *this % after;     
    temp = getPow(t/2, after);   
    result = temp * temp % after;  
    if(t%2 == 1)  
        result = *this * result % after;    
    return result;  
}    
Math Math::getPow(Math &t, Math &after)
{    
    Math div2, temp, result;
    if(t.isOne())  
        return *this % after;    
    div2 = t/2;  
    temp = getPow(div2, after);  
    result = temp *temp % after;  
    if(t.isOdd()) 
        result = *this * result % after;  
    return result;  
}   
Math Math::getPow10(int t)
{   
    int i;  
    Math after;   
    for(i=0;i<len;i++)  
        after.num[i+t] = num[i];  
    after.len = len+t;  
    return after;  
}    
bool Math::operator>=(Math &compare)
{    
    int i;
    if(len<compare.len)  
        return false;       
    if(len == compare.len)
    {  
        for(i=len-1;i>=0;i--) 
        { 
            if(num[i]>compare.num[i])  
                return true; 
            else if(num[i]<compare.num[i])  
                return false; 
        } 
        return true;
    }   
    return true;
}  
bool Math::isOdd()
{    
    if(num[0]/2*2 == num[0])
        return true;
    else 
        return false; 
}    
bool Math::isOne()
{    
    if(num[0]==1 && len==1)
        return true;
    else
        return false;
}     
void Math::print()
{   
    int i;
    for(i=len-1;i>=0;i--)  
        cout << num[i];  
    cout << endl;  
}    
Math getResult(Math a, Math b, char operate)
{   
    Math result;  
    if(operate=='+') 
        result = a+b;  
    if(operate=='-') 
        result = a-b;  
    if(operate=='*')  
        result = a*b;  
    if(operate=='/')  
        result = a/b;  
    if(operate=='%')   
        result = a%b;  
    return result;  
}  
void calculateDH()
{   
    Math Alice, Bob, K;
    string str1, str2, str3;       
    cout << "input g" << endl;  
    cin >> str1;    
    cout << "input p" << endl;  
    cin >> str2;   
    cout << "input a" << endl;  
    cin >> str3;  
    Math g(str1), p(str2), a(str3);  
    Alice = g.getPow(a, p);  
    cout << "Alice's public key: " << endl;  
    Alice.print();    
    cout << "input b" << endl;  
    cin >> str1;  
    Math b(str1);  
    Bob = g.getPow(b, p);  
    cout << "Bob's public key: " << endl;  
    Bob.print();  
    cout << "Alice's K: " << endl;  
    K = Bob.getPow(a, p);  
    K.print();   
    cout << "Bob's K: " << endl;  
    K = Alice.getPow(b, p);  
    K.print();  
}    
int main()
{  
    string m, n;
    char f;  
    cout <<"input '+' or '-' or '*' or '/' or 'd':"<<endl; 
        cin >> f;  
        if(f!='d'){
            cout << "input the first number:" << endl;  
            cin >> m;
            cout << "input the second number:" << endl;  
            cin >> n;
            Math a(m), b(n);  
            Math result = getResult(a, b, f);   
            result.print();  
            if(f=='/'){
                result = getResult(a, b, '%');
                cout << "the remainder is: ";
                result.print();
            }
        }else if(f=='d')
            calculateDH();  
    return 0;  
}  

