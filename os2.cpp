#include <iostream>
#include <algorithm>
using namespace std;

int ab;

typedef struct schedule
{
	string pro_id;
	int at,bt,ct,ta,wt,que;
}schedule;

bool compare(schedule a,schedule b)
{
	return a.at < b.at;
	/* This process will always return TRUE 
	if above condition comes*/
}

bool compare2(schedule a,schedule b)
{
	return a.bt < b.bt && a.at <= ab;
	/* This process will always return TRUE 
	if above condition comes*/
}

int main()
{
	schedule pro[10];
	int n,i,j;
	int sum=0,sum1=0;	
	cout<<"Enter the number of schedule::";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter process id";
		cin>>pro[i].pro_id;
		cout<<"enter arrival time";
		cin>>pro[i].at;
		cout<<"enter burst time";
		cin>>pro[i].bt;
		cout<<"enter queue either 1 or 2";
		cin>>pro[i].que;
	}

	sort(pro,pro+n,compare);
	pro[0].ct=pro[0].bt+pro[0].at;
	pro[0].ta=pro[0].ct-pro[0].at;
	pro[0].wt=pro[0].ta-pro[0].bt;
	for(i=1;i<=n;i++)
	{
		if(pro[i].que==1)
		{
			goto A;
		}
		else
		{
			goto B;
		}
	}

	A:
		{
		
	for(i=1;i<n;i++)
	{
	
		ab=pro[i-1].ct;
		sort(pro+i,pro+n,compare2);
		if(pro[i-1].ct<pro[i].at)
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
		}
		else
		{

			pro[i].ct=pro[i-1].ct+pro[i].bt;

		}
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		ab=pro[i-1].ct;
		sort(pro+i,pro+n,compare2);
		if(pro[i-1].ct<pro[i].at)
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
		}
		else
		{

			pro[i].ct=pro[i-1].ct+pro[i].bt;

		}
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		
	}
}
	B:
		{
		
	for(i=1;i<n;i++)
	{
	
		ab=pro[i-1].ct;
		sort(pro+i,pro+n,compare2);
		if(pro[i-1].ct<pro[i].at)
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
		}
		else
		{

			pro[i].ct=pro[i-1].ct+pro[i].bt;

		}
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		ab=pro[i-1].ct;
		sort(pro+i,pro+n,compare2);
		if(pro[i-1].ct<pro[i].at)
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
		}
		else
		{

			pro[i].ct=pro[i-1].ct+pro[i].bt;

		}
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		
	}
}
	cout<<"process"<<" "<<"arrival time"<<" "<<"burst time"<<" "<<"completion time"<<" "<<"turn around time"<<" "<<"waiting time\n";
	for(i=0;i<n;i++)
	{
		//before executing make it in one statement
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].bt
		<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt;
		sum=sum+pro[i].ta;
		sum1=sum1+pro[i].wt;
		cout<<endl;
	}
	cout<<"avg TAT ="<<sum/n<<"\n";
	cout<<"avg WT ="<<sum1/n;
	
	return 0;
}
