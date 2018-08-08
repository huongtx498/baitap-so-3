#include <iostream>
#include <fstream>
#include <string>
#define Max 1000

using namespace std;

int kiemtra ( char a[Max][5], int i, int j)// kiem tra xem 2 tu co tao thanh 1 canh khong
{
     int dem = 0;
    {
        for(int k= 0; i< 5; i++)
        {
            if(a[i][k]== a[j][k]) dem++;
        }
    }
    if(dem== 4)return 1;
    else return 0;
}


//Hàm trả về số thành phần liên thông của đồ thị
int TPLienThong(int matran[Max][Max], int n)
{
   char DanhDau[Max];
   char ThanhCong;
   int i, j;
   int Dem=0, MLT=0;            // mien lien thong
   for(i = 0; i<n; i++)
      DanhDau[i] = 0;
   do {
      j = 0;
      while(DanhDau[j]==1)   //B1: Tìm 1 đỉnh chưa được đánh dấu
         j++;
      DanhDau[j] = 1;      //Đánh dấu đỉnh tìm được
      Dem++;              //Tăng số đỉnh được đánh dấu lên 1
      MLT++;             //Tăng miền liên thông lên 1
      do {
         ThanhCong =0;   //Giả sử không còn khả năng loang
         for(i = 0; i<n; i++)
         if(DanhDau[i]==1)
            for(j = 0; j<n; j++)
            if (DanhDau[j] == 0 && matran[i][j] > 0) {
               DanhDau[j] = 1;
               ThanhCong =1;      //Còn khả năng loang
               Dem++;
               if(Dem == n) return MLT;
            }
      }while (ThanhCong == 1);   //Lặp khi còn khả năng loang
   } while(Dem<n);              //Lặp khi còn tồn tại đỉnh chưa được dánh dấu
   return MLT;
}

int main()
{
    int n= 0;    // sau se cho ra so phan tu cua mang
    char a[Max][5];
    // doc file
    ifstream world ("world.txt");
    if (world.is_open())
    {
        while (!world.eof())
        { n++;
          for(int i=0; i< 5; i++)
            world>> a[n-1][i];
        }
        n=n-1;
       world.close();
    }
    else cout << "Khong mo duoc file\n";

  // tao ma tran danh sach ke cac canh

    int matran[Max][Max];
    for(int i=0; i<n; i++)
      for(int j=i; j<n; j++)
{
    int k=kiemtra(a, i, j);
    if(k==1)
    {
    matran[i][j]=1;
    matran[j][i]=1;
    }
}
   int kq= TPLienThong(matran, n);
   cout<<" so thanh phan lien thong la: "<< kq<< endl;
   /*


   */
   // tim duong di ngan nhat giua 2 tu
   char First[Max], Last[Max];
   int f, l;
   cout<< "\n nhap vao tu dau tien ( co 5 chu cai va khong chua dau cach): ";
   for(int i=0; i< 5; i++) cin>> First[i];
   cout<< "\n nhap vao tu cuoi cung ( co 5 chu cai va khong chua dau cach): ";
   for(int i=0; i< 5; i++) cin>> Last[i];
   // tim kiem tu bat dau trong mang
   int dem= 0;
   for(int i=0; i<n; i++)
   {for(int j=0; j<5; j++)
    if(a[i][j]==First[j]) dem++;
    if(dem== 5){f= i; break;}
   }
   int Dem= 0;
   for(int i=0; i<n; i++)
   {for(int j=0; j<5; j++)
    if(a[i][j]==Last[j]) dem++;
    if(dem== 5){l= i; break;}
   }
   // ta sẽ thay từng chữ cái của từ đầu tiên  sao cho giống từ cuối cùng
       char ketqua[5][5];
       int hang= 0;
   for(int i=0; i<5; i++)
   {
      if(First[i]!=Last[i])
       {
           for(int j=0; j<n; j++)
      if(matran[f][j]> 0&&a[j][i]==Last[i])// tìm từ ở vị trí j nối với từ First và giống từ Last ở vị trí thứ i
      {
          for(int cot=0; cot<5; cot++) ketqua[hang][cot]=a[j][cot];
          hang++;
          First[i]=a[j][i];
      }
       }
   }

   {

   }
   cout<<"\n duong di ngan nhat la: "<<endl;
   for(int i=0; i< 5; i++) cout<< First[i];
   cout<< " ==>";
   for(int i=0; i< hang; i++)
   {
      for(int j=0; j<5; j++)
        cout<<ketqua[i][j];
        cout<< " ==>";
   }
    for(int i=0; i< 5; i++) cout<< Last[i];
    cout<< " ==>";

    return 0;
}
