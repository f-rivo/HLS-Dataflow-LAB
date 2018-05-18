
void pass(int tmp1[128], int b[128])
{
#pragma HLS INLINE off
 
static int j; 
  for(int i=0;i<128;i++)
    {
	j++;
      b[i] = tmp1[i];
    }
}

void split(int a[128], int tmp1[128], int tmp2[128])
{
#pragma HLS INLINE off

static int j;
  for(int i=0;i<128;i++)
    {
     j++;
      tmp1[i] = a[i];
      tmp2[i] = a[i];
    }
}

void dut(int a[128], int b[128], int c[128])
{
#pragma HLS DATAFLOW

  int tmp1[128];

  split(a,tmp1,c);
  pass(tmp1,b);
  
}
