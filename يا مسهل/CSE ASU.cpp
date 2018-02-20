#include <iostream>
#include<string>
#include<cstdlib>
#include <math.h>
#include<vector>
using namespace std;
class point//_--------------------------------------------------------------------------------------------------------------------------------------
{ public:
void setx(float a){
	x=a;
} 
void sety(float b){
	y=b;
}
float getx(){
	return x;
}
float gety(){
	return y;
} 
point(){
	x=0;
	y=0;}

private:
	float x;
	float y;};
void print(point poly[], int t)
{
	for (int i = 0; i < t; i++)
	{
		cout << "(" << poly[i].getx()<< "," << poly[i].gety()<< ")";
		if (i + 1 != t)
			cout << ",";
	}
	cout << endl;
};
int remove1(point poly[], int t, point  p[])
{

	p[0] = poly[0];
	

	int n = 1;
	for (int i = 1; i<t; i++)
	{
		if (poly[i].getx() == poly[i - 1].getx() &&poly[i].gety() == poly[i - 1].gety())
		{
			continue;
		}
		else
		{

			p[n] = poly[i];
			n++;
		}
	}

	if (poly[0].getx() == poly[t - 1].getx() &&poly[0].gety() == poly[t - 1].gety())
		n--;
	//print(p,n);
	return t-n;
}

int remove2(point poly[], int t, point p[])
{
	
	int n = 1, i = 0;
	float x, x1, y, y1;
	for (i; i < t - 1; i++)
	{

		x = poly[t - 1].getx() - poly[i].getx();
		x1 = poly[i].getx()- poly[i + 1].getx();
		y = poly[t - 1].gety() - poly[i].gety();
		y1 = poly[i].gety() - poly[i + 1].gety();

		if (((x*y1) - (y*x1)) == 0)
		{
			continue;
		}
		else
		{
			p[0] = poly[i];
			break;
		}
	}
	i++;
	for (i; i<t; i++)
	{
		x = poly[i - 1].getx() - poly[i].getx();
		x1 = poly[i].getx() - poly[i + 1].getx();
		y = poly[i - 1].gety() - poly[i].gety();
		y1 = poly[i].gety() - poly[i + 1].gety();
		
		if (((x*y1) - (y*x1)) == 0)
		{
			continue;
		}
		else
		{

			p[n] = poly[i];
			n++;
		}
	}

	x = p[0].getx() - p[n-1].getx();
	x1 = p[n-1].getx() - p[n-2].getx();
	y = p[0].gety() - p[n-1].gety();
	y1 = p[n-1].gety() - p[n-2].gety();

	if (((x*y1) - (y*x1)) == 0)
	{
		n--;
	}
	


	//print(p, n);
	return t-n;
}



int redundant(point poly[], int t,point p[])
{
	point p2[100] ;
	int s = remove1(poly, t, p2);
	int x = remove2(p2, t - s, p);
	return (x + s);
}
int checkin(vector<point> points, point p)
{
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].getx() == p.getx() && points[i].gety() == p.gety())
		{
			return i;
		}
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////
void num_of_points(point p[100][100],int total , int n[], vector<point>& all,vector <int>& num)
{
	point poly[100];
	for (int i = 0; i < total; i++)
	{
		int t = remove1(p[i], n[i], poly);
		if (all.size() == 0)
		{
			all.push_back(poly[0]);
			num.push_back(0);
		}
		for (int j = 0; j < n[i]-t; j++)
		{
				int index =checkin(all,poly[j]);
				if (index != -1)
				{
					num[index]++;
				}
				
			else
			{
				all.push_back(poly[j]);
				num.push_back(1);
			}
		}
	
	}
}


int main()//------------------------------------------------------------------------------------------------------------------------------------
{

	string str;
	cin>>str;

	string n1 = "", n2 = "";
	point polygon[100][100];
	int npoly[100] = { 0, 0 };
	int t = 0, n = 0,xx = 0, yy = 0;
	point p[100];
	vector <point> allpoints;
    vector <int> numpoints;

   



	for (int i = str.find("["); i<str.size(); i++)
	{

		if (str[i] == ';' || str[i] == ']')
		{
			n++;
			npoly[xx] = yy;
			yy = 0;
			xx++;

		}
		if (str[i] == '(')
		{
			i++;
			while (str[i] != ',')
				n1 = n1 + str[i++];
			i++;
			while (str[i] != ')')
				n2 = n2 + str[i++];

			polygon[xx][yy].setx( atof(n1.c_str()));
			polygon[xx][yy].sety(atof(n2.c_str()));
			t++;
			yy++;
			n1 = "";
			n2 = "";



		}
	}

	float minx, miny, maxx, maxy;
	minx = polygon[0][0].getx();
	maxx = polygon[0][0].getx();
	miny = polygon[0][0].gety();
	maxy = polygon[0][0].gety();
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<npoly[i]; j++)
		{
			if (polygon[i][j].getx()<minx)
				minx =polygon [i][j].getx();
			else if (polygon[i][j].getx()>maxx)
				maxx = polygon[i][j].getx();
			if (polygon[i][j].gety()<miny)
				miny = polygon[i][j].gety();
			else if (polygon[i][j].gety()>maxy)
				maxy =polygon[i][j].gety();


		}
	}
	
    string com;
	while (com != "Quit")
	{
		 getline(cin,com);
    
		if (com == "Number_Polygons")
		{
			cout << xx << endl;
		}
		else if (com == "Total_Number_Points")
		{
			cout << t << endl;
		}
		else if (com == "Minimum_X")
		{
			cout << minx << endl;
		}
		else if (com == "Maximum_X")
		{
			cout << maxx << endl;
		}
		else if (com == "Minimum_Y")
		{
			cout << miny << endl;
		}
		else if (com == "Maximum_Y")
		{
			cout << maxy << endl;
		}
		else if (com == "Enclosing_Rectangle")
		{
			cout << "(" << minx << "," << miny << "),(" << maxx << "," << miny << "),(" << maxx << "," << maxy << "),(" << minx << "," << maxy << ")" << endl;

		}
		else if (com == "Total_Redundant_Points")
		{  
			int sum = 0;
			for (int i = 0; i<xx; i++)
			{
				sum += redundant(polygon[i], npoly[i],p);
			}
			if (sum == 0)
				cout << "none" << endl;
			else
				cout << sum << endl;;
			
		}
		else if(com.substr(0,14)=="Polygon_Points")// P O L Y G O N _ P O I N T S --------------------------------------------------------------------------------------
		{ string a="";
			 a=com.substr(15);
			int A=atoi(a.c_str());
			if(A<0||A>xx)
				cout<<"none"<<endl;
			else
			{
			for(int i=0;i<=A-1;i++)
			 {
				if(i==A-1) {
					for(int j=0;j<npoly[i];j++)
					{
						cout << "(" << polygon[i][j].getx()<< "," << polygon[i][j].gety()<< ")";
						if (j+1!=npoly[i])
							cout<<",";
		                 
				} }
		     }
			}
		}
		else if(com.substr(0,14)=="Point_Polygons")// P O I N T _ P O L Y G O N S --------------------------------------------------------------------------
		{
			string b="",c=""; int found=0;
			point findp;
		
		  for(int i=15;i<com.length();i++){
				if(com[i]=='('){
					i++;
					while(com[i]!=',')
						b=b+com[i++];
					    i++;
					while(com[i]!=')')
						c=c+com[i++];
					findp.setx( atof(b.c_str()));
		         	findp.sety(atof(c.c_str()));		
				}
				
				else
					cout<<"none"<<endl;}

		  for (int i = 0; i<n; i++)
		  {
		     for (int j = 0; j<npoly[i]; j++)
		    {
			  if(findp.getx()==polygon[i][j].getx()&&findp.gety()==polygon[i][j].gety())
			  {
			        if( found==0) {
						 cout<<i+1;
						 found++; }
					else  
						cout<<","<<i+1;
			  }	 
		    }
		  }
		  if (found > 0)
				cout << endl;
			else
				cout << "none" << endl;
		
		}
		else if(com.substr(0,25)=="List_Polygons_Points More")//L I S T _P O L Y G O N S _ P O I N T S M O R E----------------------------------------------
		{  
			string d=""; int flag=0;
			d=com.substr(26);
			int D=atoi(d.c_str());
		    for(int i=0;i<xx;i++)
			  { if(D<npoly[i]-redundant(polygon[i],npoly[i],p))
		     	{    if( flag==0) {
						 cout<<i+1;
						 flag++; }
					else  
						cout<<","<<i+1;
			    }
		 	  } 
			if (flag > 0)
				cout << endl;
			else
				cout << "none" << endl;
		}

		else if(com.substr(0,25)=="List_Polygons_Points Less")//--------------------------------------------
		{ 
			string d=""; int flag=0;
			d=com.substr(26);
			int D=atoi(d.c_str());
		    for(int i=0;i<xx;i++)
			  { if(D>npoly[i]-redundant(polygon[i],npoly[i],p))
		     	{    if( flag==0) {
						 cout<<i+1;
						 flag++; }
					else  
						cout<<","<<i+1;
			    }
		 	  } 
			if (flag > 0)
				cout << endl;
			else
				cout << "none" << endl;
		}


		else if(com.substr(0,26)=="List_Polygons_Points Equal")//L I S T _ P O L Y G O N S _ P O I N T S ----------------------------------------------------
		{
			string d=""; int flag=0;
			d=com.substr(27);
			int D=atoi(d.c_str());
		    for(int i=0;i<xx;i++)
			  { if(D==npoly[i]-redundant(polygon[i],npoly[i],p))
		     	{    if( flag==0) {
						 cout<<i+1;
						 flag++; }
					else  
						cout<<","<<i+1;
			    }
		 	  } 
			if (flag > 0)
				cout << endl;
			else
				cout << "none" << endl;

		}
		else if (com.substr(0,25) == "List_Points_Polygons More")
		{
			num_of_points(polygon,xx, npoly, allpoints, numpoints);
			string num = com.substr(26);
			int n = atoi(num.c_str());
			int flag = 0;
			for (int i = 0; i < allpoints.size(); i++)
			{
				
				if (numpoints[i] > n)
				{
					if (flag != 0)
					{
						cout << ',';
					}
					cout << "(" << allpoints[i].getx() << "," << allpoints[i].gety() << ")";
					flag = 1;
				}

			}
			cout << endl;
			if (flag == 0)
				cout << "none" << endl;
			
		}

		else if (com.substr(0, 25) == "List_Points_Polygons Less")
		{
			num_of_points(polygon,xx, npoly, allpoints, numpoints);
			string num = com.substr(26);
			int n = atoi(num.c_str());
			int flag = 0;
			for (int i = 0; i < allpoints.size(); i++)
			{

				if (numpoints[i] < n)
				{
					if (flag != 0)
					{
						cout << ',';
					}
					cout << "(" << allpoints[i].getx() << "," << allpoints[i].gety() << ")";
					flag = 1;
				}

			}
			cout << endl;
			if (flag == 0)
				cout << "none" << endl;

		}
		 
		else if (com.substr(0, 26) == "List_Points_Polygons Equal")
		{
			num_of_points(polygon,xx, npoly, allpoints, numpoints);
			string num = com.substr(27);
			int n = atoi(num.c_str());
			int flag = 0;
			for (int i = 0; i < allpoints.size(); i++)
			{

				if (numpoints[i] == n)
				{
					if (flag != 0)
					{
						cout << ',';
					}
					cout << "(" << allpoints[i].getx() << "," << allpoints[i].gety() << ")";
					flag = 1;
				}

			}
			cout << endl;
			if (flag == 0)
				cout << "none" << endl;


		}

		else if (com.substr(0,17)=="Polygon_Perimeter")//P O L Y G O N _P E R I M E T E R---------------------------------------------------------------
		{
			string g="";
			float dis=0,per=0;
		    g=com.substr(18);
		    int G=atoi(g.c_str());
			if(G<0||G>xx)
			cout<<"none"<<endl;
			else
			{
			for(int i=0;i<xx;i++)
			  {
				if(i==G-1)
			      { for(int j=0;j<npoly[i];j++)
			    	{ 
						if(j!=npoly[i]-1){
						    dis=sqrt(pow(polygon[i][j].getx()-polygon[i][j+1].getx(),2)+pow(polygon[i][j].gety()-polygon[i][j+1].gety(),2));
						    per=per+dis;   }
						else {
							float distance=0,perimeter=0;
							distance=sqrt(pow(polygon[i][npoly[i]-1].getx()-polygon[i][0].getx(),2)+pow(polygon[i][npoly[i]-1].gety()-polygon[i][0].gety(),2));
							perimeter=per+distance; 
						    cout<<perimeter<<endl;  }
				    }
				   }
			  }
			}
		 }

		 else if(com.substr(0,14)=="List_Triangles")//L I S T _ T R I A N G L E S--------------------------------------------------------------------------------
		 {
			 int flag=0;
			 for(int i=0;i<xx;i++)
			 { 
		       if (npoly[i]-redundant(polygon[i],npoly[i],p)==3)
			   {  
                 {    if( flag==0) {
						 cout<<i+1;
						 flag++; }
					else  
						cout<<","<<i+1;
			     }
		 	  } 
			 }
			if (flag > 0)
				cout << endl;
			else
				cout << "none" << endl;

		 }
		 else if(com.substr(0,15)=="List_Rectangles")//L I S T _ R E C T A N G L E S-----------------------------------------------------------------------
		 {
			 float x1,x2,y1,y2,x3,x4,y3,y4,d1,d2,d3=0,d4;
			 int flag=0;
			 for(int i=0;i<xx;i++)
			 { 

				 if (npoly[i]-redundant(polygon[i],npoly[i],p)==4)
			   {  
                
					 x1 = polygon[i][1].getx() - polygon[i][0].getx();
		             x2 = polygon[i][3].getx() - polygon[i][2].getx();
		             y1 = polygon[i][1].gety() - polygon[i][0].gety();
		             y2 = polygon[i][3].gety() - polygon[i][2].gety();

					 x3 = polygon[i][2].getx() - polygon[i][1].getx();
		             x4 = polygon[i][0].getx() - polygon[i][3].getx();
		             y3 = polygon[i][2].gety() - polygon[i][1].gety();
		             y4 = polygon[i][0].gety() - polygon[i][3].gety();

					 d1=sqrt(pow(polygon[i][1].getx()-polygon[i][0].getx(),2)+pow(polygon[i][1].gety()-polygon[i][0].gety(),2));
					 d2=sqrt(pow(polygon[i][2].getx()-polygon[i][1].getx(),2)+pow(polygon[i][2].gety()-polygon[i][1].gety(),2));
					 d3=sqrt(pow(polygon[i][3].getx()-polygon[i][2].getx(),2)+pow(polygon[i][3].gety()-polygon[i][2].gety(),2));
					 d4=sqrt(pow(polygon[i][0].getx()-polygon[i][3].getx(),2)+pow(polygon[i][0].gety()-polygon[i][3].gety(),2));



		       if (((x1*y2) - (y1*x2)) == 0 &&((x3*y4) - (y3*x4)==0)&&( d1-d3==0 )&&( d2-d4==0))
		        { 

			        if( flag==0) {
						 cout<<i+1;
						 flag++; }
					else  
						cout<<","<<i+1;
			   }
		 	   } 
			 }  

			 if (flag > 0)
				cout << endl;
			else
				cout << "none" << endl;

		 }
		 else if(com.substr(0,14)=="List_Trapezoid")//L I S T _T R A P E Z O I D--------------------------------------------------------------------------------
		 { 
			 float x1,x2,y1,y2,x3,x4,y3,y4;
			 int flag=0;
			 for(int i=0;i<xx;i++)
			 { 

				 if (npoly[i]-redundant(polygon[i],npoly[i],p)==4)
			   {  
                
					 x1 = polygon[i][1].getx() - polygon[i][0].getx();
		             x2 = polygon[i][3].getx() - polygon[i][2].getx();
		             y1 = polygon[i][1].gety() - polygon[i][0].gety();
		             y2 = polygon[i][3].gety() - polygon[i][2].gety();

					 x3 = polygon[i][2].getx() - polygon[i][1].getx();
		             x4 = polygon[i][0].getx() - polygon[i][3].getx();
		             y3 = polygon[i][2].gety() - polygon[i][1].gety();
		             y4 = polygon[i][0].gety() - polygon[i][3].gety();


			     if (( (x1*y2) - (y1*x2) == 0 && (x3*y4) - (y3*x4)!=0 )||((x3*y4) - (y3*x4)==0 &&(x1*y2) - (y1*x2) != 0))
				 {
			        if( flag==0) {
						 cout<<i+1;
						 flag++; }
					else  
						cout<<","<<i+1;
			     }}
		 	   } 
			  
			    if (flag > 0)
				cout << endl;
		    	else
				cout << "none" << endl;

		 }

		 else if(com.substr(0,16)=="Inside_Rectangle")//I N S I D E _ R E C T A N G L E-----------------------------------------------------------------------
		 {
			 string t1="", t2="";
			 int npoints=0,found=0;
			 for(int i=17; i<com.length(); i++)
			 {
				if(com[i]==','){
					npoints++;
					i++; }
			    if (com[i] == '(')
		        {
				    i++;
		        	while (com[i] != ',')
				    t1 = t1 + com[i++];
			        i++;
			        while (com[i] != ')')
				    t2 = t2 + com[i++];

			       p[npoints].setx( atof(t1.c_str()));
			       p[npoints].sety(atof(t2.c_str()));
			
		           t1= "";
			       t2= "";
           
	    	    }
			 }
			 float minxx, minyy, maxxx, maxyy;
           	minxx = p[0].getx();
        	maxxx = p[0].getx();
        	minyy = p[0].gety();
        	maxyy = p[0].gety();
	
	        	for (int j = 0; j<4; j++)
         		{
		        	if (p[j].getx()<minxx)
				    minxx =p[j].getx();
			        else if (p[j].getx()>maxxx)
				    maxxx = p[j].getx();
			        if (p[j].gety()<minyy)
				    minyy = p[j].gety();
		        	else if (p[j].gety()>maxyy)
				    maxyy =p[j].gety();
        		}

				for(int i=0;i<xx;i++)
				{
					for(int j=0;j<npoly[i];j++)
					{
						if(polygon[i][j].getx()>=minxx && polygon[i][j].getx()<=maxxx && polygon[i][j].gety()>=minyy && polygon[i][j].gety()<=maxyy )
						  {
						   if(j==npoly[i]-1)
						      {
							     if( found==0) {
						           cout<<i+1;
						           found++; }
								 else 
						           cout<<","<<i+1;
						      }
						  } 
						else
							break;
					}
				} 
				if (found > 0)
				cout << endl;
			    else
				cout << "none" << endl;
		 }
		 else if(com.substr(0,13)=="Inside_Circle")//__________________________________________________________________________________________________________________
		 {
			 point center;
			 float rad, dis=0 ; int found=0;
			 string H="",I="",J=""; 
             for(int i=14;i<com.length();i++)
			 {
				if(com[i]==',')
				{
					i++;
					J=com.substr(i);
					rad=atof(J.c_str());
				}
				if(com[i]=='(') 
				{
					    i++;
					while(com[i]!=',')
						I=I+com[i++];
					    i++;
					while(com[i]!=')')
						H=H+com[i++];
					center.setx( atof(I.c_str()));
		         	center.sety(atof(H.c_str()));		
				}
			 }
			 for(int i=0;i<xx;i++)
				{
					for(int j=0;j<npoly[i];j++)
					{
						if(sqrt(pow(polygon[i][j].getx()-center.getx(),2)+pow(polygon[i][j].gety()-center.gety(),2))<=rad )
						  {
						   if(j==npoly[i]-1)
						      {
							     if( found==0) {
						           cout<<i+1;
						           found++; }
								 else 
						           cout<<","<<i+1;
						      }
						  } 
						else
							break;
					}
				} 
				if (found > 0)
				cout << endl;
			    else
				cout << "none" << endl;


         }
		 else if(com.substr(0,12)=="Polygon_Area")// P O L Y G O N _ A R E A--------------------------------------------------------------------------------------
		 { 
			 string g="";
			float dis=0,area=0;
		    g=com.substr(13);
		    int G=atoi(g.c_str());
			if(G<0||G>xx)
			cout<<"none"<<endl;
			else
			{
			for(int i=0;i<xx;i++)
			  {
				  if(i==G-1)
				  { for(int j=0;j<npoly[i];j++)
				    {
						if(j!=npoly[i]-1)
						area=area+polygon[i][j].getx()*polygon[i][j+1].gety()-polygon[i][j].gety()*polygon[i][j+1].getx();
						else
						{
							float A=0 ,total;
							A=polygon[i][npoly[i]-1].getx()*polygon[i][0].gety()-polygon[i][npoly[i]-1].gety()*polygon[i][0].getx();
							total=fabs(0.5*(A+area));
							cout<<total<<endl;
						}
				    }
				  }
			  }
			}
		 }

		 else if(com.substr(0,19)=="Polygons_Area_Range")
		 {
			 int flag=0;
			 string k="",l="";
			 float mina,maxa, area=0;
			 for(int i=19;i<com.length();i++)
			 {
				if (com[i] == ' ')
		        {
				    i++;
		        	while(com[i] != ',')
				    k = k + com[i++];
			        i++;
				    while(i!=com.length())
				    l = l+ com[i++];
					
					mina=atof(k.c_str());
					maxa=atof(l.c_str());
			       
		           k= "";
			       l= "";
           
				}
			 }

			 for(int i=0;i<xx;i++)
			 {
				 area=0;
				  { for(int j=0;j<npoly[i];j++)
				    {
						if(j!=npoly[i]-1)
						area=area+polygon[i][j].getx()*polygon[i][j+1].gety()-polygon[i][j].gety()*polygon[i][j+1].getx();
						else
						{
							float A=0 ,total=0;
							A=polygon[i][npoly[i]-1].getx()*polygon[i][0].gety()-polygon[i][npoly[i]-1].gety()*polygon[i][0].getx();
							total=fabs(0.5*(A+area));
							if(total>=mina && total<=maxa)
							{
								 if( flag==0) {
						           cout<<i+1;
						           flag++; }
				            	else  
					               cout<<","<<i+1;

						   }
				        }
				    }
			      }
			  }
			  if (flag > 0)
				cout << endl;
		      else
				cout << "none" << endl;
		 }
		 





		 else if (com == "Quit")
		{

			return 0;
		}
		else
			cout << "none";
	}

	return 0;
}
