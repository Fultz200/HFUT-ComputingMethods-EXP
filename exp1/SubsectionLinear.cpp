#include<iostream> 
#include<string> 
using namespace std;

int main()
{	double a,b; 
	double f[20];
	cout<<"enter the section:"<<endl; 
	cin>>a; 
	cin>>b;
	cout<<"enter the n(operate time):"<<endl; 
	int n; 
	cin>>n;
	double c = (b-a)/(n-1);
	double x0;
	for(int i = 0; i<=b-a;i=i+c)
	{
		x0 = i+a;
		f[i]=1/(1+x0*x0);
		//cout<<f[i]<<endl;
	}
	
	cout<<"enter the x:"<<endl; 
	double x; 
	cin>>x;
	double y =1/(1+x*x);
	
	//拉格朗日插值法预测 
	double sum1=0; 
	for(int i=0;i<=(b-a);i++){ 
		double t=f[i]; 
		for(int j=0;j<=(b-a);j++){ 
			if(i!=j){ 
						t = t*(x-(j+a)); 
						t = t/(i-j); 
					} 	
			} 
			sum1 += t;//构造插值公式并求和 
		}
	
	//分段插值法预测
	double sum2=0; 
	int d =0;
	while(x-(d+a) >c ) //判断输入的x在哪个区间 
	{ 
		d=d+1; 
	} 
	sum2=f[d]*(1-(x-(d+a))/c)+f[d+1]*((x-(d+a))/c); //构造一次插值公式 
	
	//输出结果 
	cout << "Lagrabge-->"<< sum1 << " excat:" << y << " error：" << y-sum1 <<endl; 
	cout << "Subsection Linear-->" << sum2 << " excat:"<< y << " error：" << y-sum2 <<endl; 
	system("pause"); 
	return 0;
}