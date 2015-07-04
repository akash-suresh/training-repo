#include<iostream>
using namespace std;

int precedence(char choice){
	switch(choice){
		case '+' :
		case '-' : return 1;
		case '*' :
		case '/' : return 2;
		case '^' : return 3;
	}
	return -1;
}

char* postfix(char *in_str){
	char post_str[50],stack[50],c;
	int i,k=0,tos=-1;
	stack[++tos]='#';
	for(i=0; in_str[i]!='\0';i++){
		c = in_str[i];
		if(isalpha(c)){
			post_str[k++]=c;
		}
		else if(c=='('){
			stack[++tos]=c;
		}
		else if(c==')'){
			while(stack[tos]!='('){
				post_str[k++] = stack[tos--];
			}
			tos--;
		}
		else{
			while(precedence(c)<=precedence(stack[tos])){
				post_str[k++] = stack[tos--];
			}
			stack[++tos]=c;
		}
	}
	while(stack[tos]!='#'){
		post_str[k++]=stack[tos--];
	}
	post_str[k]='\0';
	return post_str;
}
int main(){
	char in_str[50],*post_str;

	cout<<"enter the infix string : ";
	cin>>in_str;
	post_str = postfix(in_str);

	cout<<"postfix string is : "<<post_str<<endl;
	return 0;
}