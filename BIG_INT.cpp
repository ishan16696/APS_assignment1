#include<bits/stdc++.h>
using namespace std;



// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ADDITION +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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

//************************************************************ MULTIPLICATION ***********************************************

string mul(string s1,string s2){
	
	int sign;// 0 ---> +ve and 1 ---> -ve
	if(s1[0]=='-' && isdigit(s2[0])){
		s1.erase(s1.begin());
		sign=1;
	}
	if(s2[0]=='-' && isdigit(s1[0])){
		s2.erase(s2.begin());
		sign=1;
	}
	if(s1[0]=='-' && s2[0]=='-'){
		s2.erase(s2.begin());
		s1.erase(s1.begin());
		sign=0;
	}
	
	
	
	if(s1.length() > s2.length()) 
	swap(s2,s1);
   // s2 length is greater than s1 always

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
		res.erase(0,1);// erase 0th position 1 times occurence
		
		
	if(sign==1){
		res.insert(0,1,'-');
	}

	return res;
	
	
}

// ------------------------------------------------------- DIFFERENCE -----------------------------------------------------

string difference(string s1,string s2)
{

     	if(s1.length()<s2.length())
		swap(s2,s1);
		if(s1.length()==s2.length())
		{
			//for (int i=0; i<s1.length(); i++) 
             //  if (s1[i] < s2[i]) 
              //  { 
                //	swap(s1,s2); 
               //     break;
               //}
			if(s1<s2){
				swap(s1,s2);

			}

		}

	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
    string result="";
	int borrow=0,last=0,i=0;
	while(i<s2.length())
	{	
		last=(s1[i]-'0')-(s2[i]-'0')-borrow;
		if(last<0)
		{
			last=(s1[i]-'0')+10-(s2[i]-'0')-borrow;
			
			borrow=1;
		}
		else
			borrow=0;
		result.append(to_string(last));
    i++;
    }

    while(i<s1.length()){
         last=(s1[i]-'0')-borrow;
         if(last<0)
		{
			last=last+10;
			borrow=1;  
		}
		else
			borrow=0;
		
		result.append(to_string(last));
    i++;
    }
       
       reverse(result.begin(),result.end());

    while(result[0] == '0' && result.length()!=1) // erase leading zeros
		result.erase(0,1);
       
     return result;
}


string diff(string s1,string s2){
	
	if(s1[0]=='-' && isdigit(s2[0])){
		s1.erase(s1.begin());
		string s3=add(s1,s2);
		s3.insert(0,1,'-');
		return s3;
	}
	if(s2[0]=='-' && isdigit(s1[0])){
		s2.erase(s2.begin());
		string s3=add(s1,s2);
		return s3;
	}
	
	if(isdigit(s1[0]) && isdigit(s2[0]))
	{
       // + + wala case
		int sign;
		if(s1.length() > s2.length() || (s1.length()==s2.length() && s1 >= s2))
  		sign=0;// means +ve
  		else
  		sign=1;	// means -ve
        string s3=difference(s1,s2);
        if(sign==1){
		s3.insert(0,1,'-');
	    }
      return s3;


}// + + wala case


  if(s1[0]=='-' && s2[0]=='-'){
  		int sign;
  		s1.erase(s1.begin());
  		s2.erase(s2.begin());
  		if(s1.length() > s2.length() || (s1.length()==s2.length() && s1 > s2))
  		sign=1;// means -ve
  		else
  		sign=0;	// means +ve
      
      string s3=difference(s1,s2);
      if(sign==1){
		s3.insert(0,1,'-');
	}

	return s3;

	}

	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*string diffMod(string number1, string number2)
{
	string sub = (number1.length()>number2.length())? number1 : number2;
	int differenceInLength = abs( (int)(number1.size() - number2.size()) );

	if(number1.size() > number2.size())	
		number2.insert(0, differenceInLength, '0');

	else
		number1.insert(0, differenceInLength, '0');

	for(int i=number1.length()-1; i>=0; --i)
	{
		if(number1[i] < number2[i])
		{
			number1[i] += 10;
			number1[i-1]--;
		}
		sub[i] = ((number1[i]-'0')-(number2[i]-'0')) + '0';
	}

	while(sub[0]=='0' && sub.length()!=1) // erase leading zeros
		sub.erase(0,1);

	return sub;
}*/

/*string diffMod(string a,string b){
	string z=diff(a,b);
	if(z[0]=='-')
		z.erase(a.begin());
	return z;
}
*/


/*string sub(string &str1 , string &str2)
{
    string s1 = str1 , s2 = str2 ;
    string result;  
    s2.insert(s2.size(),s1.size() - s2.size(),'0') ;
    int borrow = 0, i = 0 , diff = 0;
    for(int i =0  ; i < s1.size() ; i++)
    {
        diff = s1[i] - s2[i] - borrow ; 
        if(diff < 0)
        {
            borrow = 1 ;
            diff += 10;
        }
        else borrow = 0 ;
        result.insert(i,1,diff + 48) ; 
    }
    reverse(result.begin(), result.end()) ; 
    
    return result; 
}*/
////////////////////////////////////////////////// DIVISION ////////////////////////////////////////////////////////////////////////////

string div(string s1,string s2){
 // by repeated subtraction
 string count="";
 //int count=0;
 string s3;
 if(s1.length() < s2.length() || (s1.length()==s2.length() && s1 < s2)){
     return to_string(count.length());
 }

 while(s1.length() > s2.length() || (s1.length()==s2.length() && s1 >s2) )
 {
 	
  s3=diff(s1,s2);
  
  s1=s3;
 // cout << s1 << endl;
  //count++;
  count.append("1");
  //cout << count << endl;
 }
  
   return  to_string(count.length());
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% GCD  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/*string gcd(string a,string b){
      if(b=="0" ){
       return a;
      }
      else if((a.compare(b))==0)
      	  return a;
      else if(a=="1" || b=="1")
      	 return to_string(1);
      else{
      	cout << "a:"<<a << endl;
      	cout << "b:"<<b << endl;
      	gcd(b,diff(a,mul(div(a,b),b)));
      }
      //return a;
}*/
/*
string gcd(string a, string b) 
{ 
   string num1,num2;
   while(1){
   	num1=a;
   	num2=b;
   	if((a.compare(b))==0)
   		return a;
   	if(a=="0" || b== "0" )
   		return to_string(0);
   
   else{
   	
   	
num1=diffMod(a,b);
cout << num1 << endl;
num2=b;
cout << num2 << endl;
   }
}
} */




//.................................................... MAIN() .............................................................................

int main(){
    
    int t,k;
    scanf("%d",&t);
    while(t--){
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	string s3;
    scanf("%d",&k);
    switch(k)
    {
     case 1:
          s3=add(str1,str2);
          cout << s3 << endl;
          break;
     case  2:
     	  s3=diff(str1,str2);
     	  cout << s3 << endl;
          break;
     case 3:
          s3=mul(str1,str2);
          cout << s3 << endl;
          break;
     case 4:
          s3=div(str1,str2);
          cout << s3 << endl;
          break; 
     /*case 5:
          s3=gcd(str1,str2);
          cout << s3 << endl;
          break;*/

      }
  }
	return 0;
}
