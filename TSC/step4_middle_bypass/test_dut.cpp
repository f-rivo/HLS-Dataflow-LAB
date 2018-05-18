#include <stdio.h>
#include <iostream>

void dut(int a[128], int b[128], int c[128]);

int main()
{

  int a[512], b[512], c[512];

  for(int i=0;i<512;i++)
    {
      a[i] = i;
    }

 for(int i=0;i<512;i++)
    {
      b[i] = i;
    }


  std::cout <<"Starting DUT:"<<std::endl;
  for(int p=0;p<4;p++)
    {
      dut(&a[p*128],&b[p*128],&c[p*128]);
    }
  std::cout <<"after DUT"<<std::endl;
  
  for(int j=0;j<512;j++)
    {
      if(c[j] !=  a[j] + b[j] )
	{
	  std::cout<<"value of i is "<< j << "value of a[j] is " << a[j] << "value of out b[j] is " << b[j] << "value of c[j] is " << c[j] <<std::endl;
	  return 1;
	  break;
	}
    }
  
  return 0;

}
