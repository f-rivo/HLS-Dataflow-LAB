
void pass_buffer(int tmp1[128], int b[128])
{
#pragma HLS INLINE off
  for(int i=0;i<128;i++)
    {
      b[i] = tmp1[i];
    }
  
}

void pass(int tmp1[128], int b[128])
{
#pragma HLS INLINE off
  for(int i=0;i<128;i++)
    {
      b[i] = tmp1[i];
    }
}

void split(int a[128], int tmp1[128], int tmp2[128])
{
#pragma HLS INLINE off

  for(int i=0;i<128;i++)
    {
      tmp1[i] = a[i];
      tmp2[i] = a[i];
    }  
}

void dut(int a[128], int b[128], int c[128])
{
#pragma HLS DATAFLOW

  int tmp1[128], tmp2[128];
#pragma HLS STREAM variable=tmp1 depth=128 dim=1
#pragma HLS STREAM variable=tmp2 depth=128 dim=1
  split(a,tmp1,tmp2);
  pass(tmp1,b);
  pass_buffer(tmp2,c);
}
