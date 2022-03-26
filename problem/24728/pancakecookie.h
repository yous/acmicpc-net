class PanCakeCookie{
private:
	int w, h;
	int x, y, t;
	int score;
	int maxC, curC;
	int u, d;
public:
	PanCakeCookie(int w, int h, int maxC, int u, int d);

	int getX();
	int getY();
	int getU();
	int getD();
	int getScore();
	int getC();

	void reset();
	void setU(int x);
	void setD(int x);
	void setC(int x);
	void setT(int t);  
};
