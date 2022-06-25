

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

bool isSame(string s){
    bool temp=true;
    int center=s.size()/2;
    for(int i = 1 ; 0<=center-i;i++){
        if(string(1,s.at(center))!=string(1,s.at(center-i))){
            temp=false;
            return temp;
        }
        if(center+i<s.size()){
            if(string(1,s.at(center-i))!=string(1,s.at(center+i))){
                temp=false;
                return temp;
            }
        }
    }
    return temp;
}
bool inPalindromic(string s){
    bool tempBool=true;
    int center=(s.size()-1)/2;
    for(int i = 1 ;0<=center-i;i++){
        if(string(1,s.at(center-i)) != string(1,s.at(center+i))) {
            tempBool = false;
            return tempBool;
        }
    }
    return tempBool;
}

string longestPalindrome(string s) {
    string temp;
    string temp2;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            string tempV2=s.substr(i,s.size()-j-i);
            if(s.substr(i,s.size()-j-i).size()%2==0){
                if(isSame(s.substr(i,s.size()-j-i))){
                    temp=s.substr(i,s.size()-j-i);
                }
                else {
                    string tempV3 = s.substr(i,s.size()-j-i);
                    tempV3.insert(tempV3.size() / 2, "a");
                    if (inPalindromic(tempV3))
                        temp = s.substr(i,s.size()-j-i);
                }
            }
            else if(s.substr(i,s.size()-j-i).size()%2!=0 && inPalindromic(s.substr(i,s.size()-j-i))){
                temp=s.substr(i,s.size()-j-i);
            }

            if(temp2.size()<temp.size())
                temp2=temp;
        }
    }
    return temp2;
}

int reverse(int x) {
    if(x>INT32_MAX)
        return 0;
    if(x<INT32_MIN)
        return 0;
    int i=10;
    int reverse=1;
    if(x<0){
        reverse=-1;
        if(x!=-2147483648)
            x=x*reverse;
        else {
            x=2147483647;
            reverse=-1;
        }
    }
    vector<int> collector;
    while(x>0){
        collector.push_back(x%i);
        x=(x-x%i)/i;
    }
    i=1;
    int result=0;
    while(collector.size()>0){
        int temp=result+collector.at(collector.size()-1)*i;
        if((i<1000000000 || collector.at(collector.size()-1)<2 || result<=147483647))
            result=result+collector.at(collector.size()-1)*i;
        else
            return 0;
        collector.pop_back();
        if(collector.size()>0)
            i*=10;
    }
    if(result*reverse>INT32_MAX)
        return 0;
    if(result*reverse<INT32_MIN)
        return 0;
    if(result!=2147483647 || reverse!=-1)
        return result*reverse;
    else{
        return -2147483648;
    }
}



 // Driver code
 int main()
 {
    /*isSame("cb");
    cout<<longestPalindrome("babad")<<endl;
    cout<<longestPalindrome("cbbd")<<endl;
    cout<<longestPalindrome("a")<<endl;
    cout<<longestPalindrome("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy")<<endl;
    cout<<longestPalindrome("tattarrattat")<<endl;
    cout<<longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth")<<endl;
*/
    /*cout<<reverse(123)<<endl;
    cout<<reverse(-123)<<endl;
    cout<<reverse(120)<<endl;*/
    cout<<reverse(1534236469)<<endl;
    cout<<reverse(-2147483412)<<endl;
    cout<<reverse(-2147483648)<<endl;
    cout<<reverse(1563847412)<<endl;
    cout<<pow(2,31)-1;
    return 0;
 }


