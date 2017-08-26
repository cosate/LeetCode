class Solution {
public:
    struct point
	{
		int x;
		int y;
		point()
		{
			x = 0;
			y = 0;
		}
		point(int i, int j)
		{
			x = i;
			y = j;
		}
		point & operator =(const point& a)
		{
			x = a.x;
			y = a.y;
			return *this;
		}
	};

	struct rectangle
	{
		point leftdown;
		point rightup;
		point leftup;
		point rightdown;
		int area;
		rectangle(int A, int B, int C, int D)
		{
			leftdown = point(A, B);
			rightup = point(C, D);
			leftup = point(A, D);
			rightdown = point(C, B);
			area = (C - A) * (D - B);
		}
	};


	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		rectangle rec1 = rectangle(A, B, C, D);
		rectangle rec2 = rectangle(E, F, G, H);
		return rec1.area + rec2.area - calcoincide(rec1, rec2);
	}

	int calcoincide(rectangle rec1, rectangle rec2)
	{
		if (rec1.leftdown.x > rec2.leftdown.x)
		{
			rectangle temp = rec1;
			rec1 = rec2;
			rec2 = temp;
		}

		if (rec1.rightup.x <= rec2.leftdown.x || rec1.rightup.y <= rec2.leftdown.y)
			return 0;
		else
		{
			if (rec2.leftup.y <= rec1.leftdown.y)
				return 0;
			else
			{
				int a = (min(rec1.leftup.y, rec2.leftup.y) - max(rec1.leftdown.y, rec2.leftdown.y))*
					(min(rec1.rightdown.x, rec2.rightdown.x) - rec2.leftdown.x);
				return a;
			}
		}
	}
};