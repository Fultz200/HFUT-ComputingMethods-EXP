#include<iostream>
#include<vector>
#include"ComplexTrapezoidFormula.h"
#include"ComplexSimpsonFormula.h"
#include"RombergIntergral.h"
#include<math.h>

using namespace std;
int main(void){
    int n;
    double a;
    double b;
    double MarginOfError;
    int nChoice;//菜单控制
    do{
		cout<<"0-->exit."<<endl;
		cout<<"1-->RombergIntergral"<<endl;
		cin>>nChoice;
        switch(nChoice)
		{
		case 0:  //退出程序
			system("cls");  //清除屏幕
			cout<<"<-- exit -->"<<endl;  //选择退出
			break;
        
        case 1:
        {
            system("cls");  //清除屏幕
            cout<<"enter the section and the error accuracy."<<endl;
            cin>>a>>b>>MarginOfError;
            double result = RomberIntergral(a,b,MarginOfError);
            cout<<"the values we get."<<result<<endl;
            cout<<"K"<<"        "<<"T"<<"           "<<"S"<<"         "<<"C"<<"          "<<"R"<<endl;
            
            cout<<"0"<<"    "<<ComplexTrapezoidFormula(0,1,1)<<endl;
            cout<<"1"<<"    "<<ComplexTrapezoidFormula(0,1,2)<<"    "<<ComplexSimpsonFormula(0,1,1)<<endl;
            cout<<"2"<<"    "<<ComplexTrapezoidFormula(0,1,4)<<"    "<<ComplexSimpsonFormula(0,1,2)<<"  "<<((16/15.0) * ComplexSimpsonFormula(0,1,2) - (1/15.0) * ComplexSimpsonFormula(0,1,1))<<endl;
            cout<<"3"<<"    "<<ComplexTrapezoidFormula(0,1,8)<<"    "<<ComplexSimpsonFormula(0,1,4)<<"  "<<((16/15.0) * ComplexSimpsonFormula(0,1,4) - (1/15.0) * ComplexSimpsonFormula(0,1,2))<<"  "<<RomberIntergral(0,1,0.0000001)<<endl;
            cout<<"4"<<"    "<<ComplexTrapezoidFormula(0,1,16)<<"    "<<ComplexSimpsonFormula(0,1,8)<<"  "<<((16/15.0) * ComplexSimpsonFormula(0,1,8) - (1/15.0) * ComplexSimpsonFormula(0,1,4))<<"  "<<RomberIntergral(0,1,0.0000001)<<endl;
    
            /*
            cout<<"0"<<"    "<<Tck[0]<<endl;
            cout<<"1"<<"    "<<Tck[1]<<"    "<<Sck[0]<<endl;
            cout<<"2"<<"    "<<Tck[2]<<"    "<<Sck[1]<<"    "<<Cck[0]<<endl;
            cout<<"3"<<"    "<<Tck[3]<<"    "<<Sck[2]<<"    "<<Cck[1]<<Rck[0]<<endl;
            cout<<"4"<<"    "<<Tck[4]<<"    "<<Sck[3]<<"    "<<Cck[2]<<Rck[1]<<endl;
            */
            cout<<"the 4 result is:"<<result<<endl;

            system("pause");
            system("cls");
        }
        break;
        

        default:
			cout<<"wrong number."<<endl;
			break;
        }
    }while(nChoice != 0);

        return 0;
}