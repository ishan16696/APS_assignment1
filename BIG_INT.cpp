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
			/*for (int i=0; i<s1.length(); i++) 
               if (s1[i] < s2[i]) 
                { 
                	swap(s1,s2); 
                    break;
               }*/
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
		if(s1.length() > s2.length() || (s1.length()==s2.length() && s1 > s2))
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
 	
  s3=difference(s1,s2);
  
  s1=s3;
 // cout << s1 << endl;
  //count++;
  count.append("1");
  //cout << count << endl;
 }
  
   return  to_string(count.length());
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% GCD  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

string gcd(string a,string b){
      if(b.empty()){
       return a;
      }
      else{
      	gcd(b,difference(a,mul(div(a,b),b)));
      }
}


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
     case 5:
          s3=gcd(str1,str2);
          cout << s3 << endl;
          break;

      }
  }
	return 0;
}
