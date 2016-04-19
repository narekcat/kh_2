struct expen_gn
{
public:
	char mat[100][100];
};

class zujg:public CObject
{
public:
	short int K,N;
	expen_gn* p;
	int all_drip;
	int this_drip[100];
	short int gumar[101][102];
	short int index;
	void run(double& W,double& S);
	void SetParam(short int,short int);
	void Serialize(CArchive&);
	DECLARE_SERIAL(zujg);
};