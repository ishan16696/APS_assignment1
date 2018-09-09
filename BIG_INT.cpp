#include<bits/stdc++.h>
//#include<string>
using namespace std;

string add(string str1,string str2){
	
	if(str2.length()>str1.length())
	swap(str2,str1);
	
	reverse(str1.begin(),str1.end());
	reverse(str2.begin(),str2.end());
	
	string result="";
	int sum,carry=0,last=0,i=0;
	while(i<str2.length())
	{
		sum=(str1[i]-'0')+(str2[i]-'0')+carry;
		last=sum%10;
		carry=sum/10;

		result.append(to_string(last));
	//	cout << result << endl;
		i++;
	}
	
	while(i<str1.length()){
		sum=(str1[i]-'0')+carry;
		last=sum%10;
		carry=sum/10;

		result.append(to_string(last));
	//	result.append(to_string(carry+(str1[i]-'0')));
	//	carry=0;
		i++;
	}
	
	if(carry){
		result.append(to_string(carry));
	}
	reverse(result.begin(),result.end());
	//cout << result << endl;
	return result;
	
}

/*bool which_small(string s1,string s2){
  
    if (s1.length() < s2.length()) 
    return true; 
    if (s2.length() < s1.length()) 
    return false; 
  
    for (int i=0; i<2; i++) 
    if (s1[i] < s2[i]) 
        return true; 
    else if (s1[i] > s2[i]) 
        return false; 
  
    return false; 
    
	}
	



void diff(string str1,string str2){
	
	
	//str1 must be larger
	if(which_small(str1,str2))
	swap(str2,str1);
	
	cout << str1 << endl;
	cout << str2 << endl;
	
/*	reverse(str1.begin(),str1.end());
	reverse(str2.begin(),str2.end());

	
	string result="";
	int dif,borrow=0,last=0,i=0;
	while(i<str2.length()){
		if(str1[i]-str2[i]<0){
		   dif= (str1[i]-'0')+10-(str2[i]-'0')+	borrow;
		   borrow=1;
		}
		
		++i;
	}
}*/

void mul(string str1,string str2){
	string s1,s2;
	int sign;// 0 ---> +ve and 1 ---> -ve
	if(str1[0]=='-' && isdigit(str2[0])){
		s1=str1.substr(1);
		sign=1;
	}
	if(str2[0]=='-' && isdigit(str1[0])){
		s2=str2.substr(1);
		sign=1;
	}
	if(str1[0]=='-' && str2[0]=='-'){
		s2=str2.substr(1);
		s1=str1.substr(1);
		sign=0;
	}
	
	/*if( isdigit(s1[0]) ) // if not signed
	{
		setNumber(s);
		sign = false; // +ve
	}
	else
	{
		setNumber( s.substr(1) );
		sign = (s[0] == '-');
	}*/
	
	if(s1.length() > s2.length()) 
	swap(s2,s1);

	string res = "0";
	for(int i=s1.length()-1; i>=0; --i)
	{
		string temp = s2;
		int currentDigit = s1[i]-'0';
		int carry = 0;

		for(int j=temp.length()-1; j>=0; --j)
		{
			temp[j] = ((temp[j]-'0') * currentDigit) + carry;

			if(temp[j] > 9)
			{
				carry = (temp[j]/10);
				temp[j] -= (carry*10);//temp[j]=temp %10;
			}
			else
				carry = 0;

			temp[j] += '0'; // back to string 
		}

		if(carry > 0)
			temp.insert(0, 1, (carry+'0'));// 0th index pe 1 times carry daal do
		
		temp.append((s1.length()-i-1), '0'); // as like mult by 10, 100, 1000, 10000 and so on
        // Appends 10 occurrences of '$'  to str 
       //  str.append(10, '$');
		res = add(res, temp); // O(n)
	}

	while(res[0] == '0' && res.length()!=1) // erase leading zeros
		res.erase(0,1);// erase 0th position 1times occurence
		
		
	if(sign==1){
		res.insert(0,1,'-');
	}

	cout <<  res << endl;
	
	
}

int main(){
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
    //cout <<	add(str1,str2);
  	mul(str1,str2);
	return 0;
}
