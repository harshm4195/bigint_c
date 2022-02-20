#include <stdio.h>
#include<string.h>
#include<malloc.h>
void add(char *,char *);
void sub(char *,char *);
void multiply(char *,char *);
void reverse(char *);
void swap(char **,char **);
void swap1(int *,int *);
int main()
{
    int c=1;
    while(c>=1)
    {
        int choice;
        printf("add 1 \nsub 2 \nmultiply 3 \n");
        scanf("%d",&choice);
        switch(choice)
        {
            char a[310],b[310];
            case 1:
            {
             scanf("%s%s",a,b);   
                add(a,b);
                break;
            }
            case 2:
            {
                 scanf("%s%s",a,b);
             sub(a,b);
             break;
            }
             case 3:
             {
                 scanf("%s%s",a,b);
          multiply(a,b);
          break;
             }
           default :
           {
               printf("ReEnter");
               break;
           }
        }
        printf("press 0 for exit\npress 1 for continue\n");
        scanf("%d",&c);
    }
}
void add(char a[],char b[])
{
    char c[310]="";
    
    int l=0,carry=0,flag=0;
    if((a[0]!='-' && b[0]!='-') || (a[0]=='-' && b[0]=='-'))
    {
        if(a[0]=='-'&& b[0]=='-')
        {
            a[0]='0';
            b[0]='0';
            flag=1;
        }
    if(strlen(a)>strlen(b))
    {
        for(int i=0;i<strlen(b);i++)
        {
            int x=(a[strlen(a)-i-1]-48)+(b[strlen(b)-i-1]-48);
            c[l]=(x+carry)%10;
            carry=(x+carry)/10;
            l++;
        }
        for(int i=0;i<strlen(a)-strlen(b);i++)
        {
            c[l]=((a[i]-48)+carry)%10;
            carry=((a[i]-48)+carry)/10;
            l++;
        } 
    }
    else
    {
         for(int i=0;i<strlen(a);i++)
        {
            int x=(b[strlen(b)-i-1]-48)+(a[strlen(a)-i-1]-48);
            c[l]=(x+carry)%10;
            carry=(x+carry)/10;
            l++;
        }
        for(int i=0;i<strlen(b)-strlen(a);i++)
        {
            c[l]=((b[i]-48)+carry)%10;
            carry=((b[i]-48)+carry)/10;
            l++;
        }
    }
    if(carry!=0)
    {
    c[l]=carry;
    l++;
    }
    if((l-1)>310)
    printf("limit exceeded\n");
    else
    {
        if(flag==1)
        printf("-");
    for(int i=l-1;i>=0;i--)
    printf("%d",c[i]);
    printf("\n");
    }
    }
    else
    {
           int n =strlen(a), m = strlen(b);
            reverse(a);
           reverse(b);
  char *aa=(char*)malloc(sizeof(char)*310);
  for (int i = 0; i < n; i++) 
  aa[i] = a[i];
  aa[n] = '\0';
  if (n == 0 || m == 0) return;
  int nega = (aa[n - 1] == '-') ? 1 : 0;
  int negb = (b[m - 1] == '-') ? 1 : 0;
  if (nega + negb==1) 
  {
    n = (aa[n - 1] == '-') ? n - 1 : n;
    m = (b[m - 1] == '-') ? m - 1 : m;
    int neg = nega;
    if (n < m) 
    {
      neg = negb;
  swap(&aa,&b);
      swap1(&n, &m);
    }
    if (n==m)
    {
      for (int i =n-1; i >= 0; i--) 
      {
        if (aa[i] > b[i])
        {
          break;
        }
        else if (aa[i] < b[i]) 
        {
          neg = negb;
           swap(&aa,&b);
          break;
        }
      }
    }
    for(int i=0;i<n;i++) 
    {
      int x = aa[i] - '0';
      int y = (i < m) ? b[i] - '0' : 0;
      if (x >= y) 
      {
        x -= y;
        c[i] = x + '0';
      }
      else 
      {
        for (int j = i + 1; j < n; j++)
        {
          if (aa[j] > '0') 
          {
            aa[j]--;
            for (int k = i + 1; k < j; k++) 
            aa[k] = '9';
            break;
          }
        }
        c[i] = 10 + x - y + '0';
      }
    }
    if (neg) 
    {
      c[n] = '-';
      c[n + 1] = '\0';
      reverse(c);
    }
    else 
    {
      c[n] = '\0';
      reverse(c);
    }
    if(strlen(c)>310)
    printf("limit exceeded");
    else
    for(int i=0;i<strlen(c);i++)
    printf("%c",c[i]);
    printf("\n");
     }
     
    }
}
void swap(char **str1, char **str2)
{
  char *temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}  
void swap1(int *x,int *y)
{
    int m=*x;
    *x=*y;
    *y=m;
}
void sub(char aa[],char b[])
{
     char c[310]="";
   
 if(((aa[0]!='-' && b[0]=='-') || (aa[0]=='-' && b[0]!='-')))
     {
         if(aa[0]=='-' && b[0]!='-')
         {
         aa[0]='0';
         printf("-");
         }
         else
         b[0]='0';
         add(aa,b);
     }
     else
     {
           int n =strlen(aa), m = strlen(b);
           if(b[0]=='-')
           {
           m=m-1;
           }
           else
           b[0]='-';
            reverse(aa);
           reverse(b);
  char *a=(char*)malloc(sizeof(char)*310);
  for (int i = 0; i < n; i++) 
  a[i] = aa[i];
  a[n] = '\0';
  if (n == 0 || m == 0) return;
  int nega = (a[n - 1] == '-') ? 1 : 0;
  int negb = (b[m - 1] == '-') ? 1 : 0;
  if (nega + negb==1) 
  {
    n = (a[n - 1] == '-') ? n - 1 : n;
    m = (b[m - 1] == '-') ? m - 1 : m;
    int neg = nega;
    if (n < m) 
    {
      neg = negb;
      swap(&a, &b);
      swap1(&n, &m);
    }
    if (n==m)
    {
      for (int i =n-1; i >= 0; i--) 
      {
        if (a[i] > b[i])
        {
          break;
        }
        else if (a[i] < b[i]) 
        {
          neg = negb;
          swap(&a,&b);
          break;
        }
      }
    }
    for(int i=0;i<n;i++) 
    {
      int x = a[i] - '0';
      int y = (i < m) ? b[i] - '0' : 0;
      if (x >= y) 
      {
        x -= y;
        c[i] = x + '0';
      }
      else 
      {
        for (int j = i + 1; j < n; j++)
        {
          if (a[j] > '0') 
          {
            a[j]--;
            for (int k = i + 1; k < j; k++) 
            a[k] = '9';
            break;
          }
        }
        c[i] = 10 + x - y + '0';
      }
    }
  if (neg) 
  {
      c[n] = '-';
      c[n + 1] = '\0';
      reverse(c);
    }
    else {
      c[n] = '\0';
      reverse(c);
    }
    if(strlen(c)>310)
    printf("limit exceeded");
    else
    for(int i=0;i<strlen(c);i++)
    printf("%c",c[i]);
    printf("\n");
     }
     
}
}
void reverse(char *str1)  
{  
    int len, temp;  
    len = strlen(str1); 
    for (int i = 0; i < len/2; i++)  
    {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
    int addition(char c[], int idx, int x, int carry)
{
  int sum = (c[idx] - '0') + x + carry;
  c[idx] = (sum % 10) + '0';
  return sum / 10;
}

void multiply(char a[], char b[]) 
{
  int n =strlen(a), m =strlen(b);
  reverse(a);
  reverse(b);
  int last = -1;
  if (n==0 || m==0) return;
  int na=(a[n - 1]=='-') ?  1 : 0;
  int nb=(b[m - 1]=='-') ?  1 : 0;
  n =(a[n - 1]=='-') ? n - 1 : n;
  m =(b[m - 1]=='-') ? m - 1 : m;
  char c[310] ;
  for(int i=0;i<310;i++)
  c[i]='0';
  for (int i = 0; i < m; i++) {
    int x=b[i]-'0';
    int carry=0;
    int carry2=0;
    for (int j = 0;j<n;j++)
    {
      int y = (a[j] - '0');
      int prod = y * x + carry;
      carry2 = addition(c, i + j, prod % 10, carry2);
      carry = prod / 10;
      last=i+j;
    }
    if (carry) 
    {
      last = i + n;
      carry2 = addition(c, i + n, carry, carry2);
      if (carry2) {
        last = i + n + 1;
        addition(c, i + n + 1, carry2, 0);
      }
    }
    else if (carry2) {
      last = i + n;
      addition(c, i + n, carry2, 0);
    }

  }

  if (na+nb==1) {
    c[last+1]='-';
    c[last+2]='\0';
  }
  else
  {
      c[last+1]='\0';
  }
  reverse(c);
  if(strlen(c)>310)
  printf("limit exceeded");
  else
  {
      int j,flag=0;
  for(int i=0;i<strlen(c);i++)
  {
  printf("%c",c[i]);
  }
}
printf("\n");
}

    

