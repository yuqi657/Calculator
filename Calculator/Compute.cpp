#include"Calculator.h"
#include"Matrix.h"
#include"HugeInt.h"
#include<string>
#include"Complex.h"
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include"Polynomial.h"
#include<process.h>

//void gotoxy(int x, int y);		//绘制函数图像所需要的goto函数

void Calculator::compute()
{//用来封装计算的函数
	printRequest();
	int choice;
	while (cin>>choice)
	{
		switch (choice)
		{
		case 1:
			matrixCompute();
			break;

		case 2:
			hugeIntCompute();
			break;

		case 3:
			complexCompute();
			break;

		case 4:
			pictureDraw();
			break;

		case 5:
			polynomialCompute();
			break;

		case 6:
			simpleCompute();
			break;

		case 7:
			simpleFunction();
			break;

		case 8:
			beautifulCompute();
			break;

		default:
			break;
		}
		system("pause");
		system("cls");
		printRequest();
	}

}

void printRequest()
{
	cout << "****************************************************" << endl;
	cout << "***** Please choose which computation you want *****" << endl;
	cout << "***** 1. MatrixCompute       2. HugeIntCompute *****" << endl;
	cout << "***** 3. ComplexCompute      4. PictureDraw    *****" << endl;
	cout << "***** 5. PolynomialCompute   6. SimpleCompute  *****" << endl;
	cout << "***** 7. SimpleFunction      8. BeautifulCal   *****" << endl;
	cout << "****************************************************" << endl;
}

void matrixCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. MatrixAdd            2. MatrixSubstract *****" << endl;
	cout << "***** 3. MatrixProductReal    4. MatrixProduct   *****" << endl;
	cout << "******************************************************" << endl;
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:
	{
		cout << "请输入矩阵行列数：" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		Matrix B = Matrix(r, c);
		B.setMember();
		Matrix C = Matrix(r, c);
		C = A + B;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	case 2:
	{
		cout << "请输入矩阵行列数：" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		Matrix B = Matrix(r, c);
		B.setMember();
		Matrix C = Matrix(r, c);
		C = A - B;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	case 3:
	{
		cout << "请输入矩阵行列数：" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		cout << "请输入所乘实数：" << endl;
		double real;
		cin >> real;
		Matrix C = Matrix(r, c);
		C = A * real;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	case 4:
	{
		cout << "请输入矩阵1的行列数：" << endl;
		int r1, c1;
		cin >> r1 >> c1;
		Matrix A = Matrix(r1, c1);
		A.setMember();
		cout << "请输入矩阵2的行列数：" << endl;
		int r2, c2;
		cin >> r2 >> c2;
		Matrix B = Matrix(r2, c2);
		B.setMember();
		Matrix C = Matrix();
		C = A * B;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	default:
		break;
	}
}

void hugeIntCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. HugeNumberAdd    2. HugeNumberSubstract *****" << endl;
	//cout << "*****           3. HugeNumberProduct             *****" << endl;
	cout << "******************************************************" << endl;
	//detect what to do
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:		//1. HugeNumberAdd
	{
		string val1, val2;
		cout << "请输入一个数据： ";
		cin >> val1;
		cout << "请输入另一个数据： ";
		cin >> val2;

		HugeInt num1 = HugeInt(val1);
		HugeInt num2 = HugeInt(val2);

		HugeInt result = HugeInt();
		result = num1 + num2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 2:		//2. HugeNumberSubstract
	{
		string val1, val2;
		cout << "请输入一个数据： ";
		cin >> val1;
		cout << "请输入另一个数据，要使它比第一个数据小： ";
		cin >> val2;

		HugeInt num1 = HugeInt(val1);
		HugeInt num2 = HugeInt(val2);

		HugeInt result = HugeInt();
		result = num1 - num2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 3:		// 3. HugeNumberProduct 
	{
		string val1, val2;
		cout << "请输入一个数据： ";
		cin >> val1;
		cout << "请输入另一个数据： ";
		cin >> val2;

		HugeInt num1 = HugeInt(val1);
		HugeInt num2 = HugeInt(val2);

		HugeInt result = HugeInt();
		result = num1 * num2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	default:
		break;
	}
}

void complexCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. ComplexAdd          2. ComplexSubstract *****" << endl;
	cout << "***** 3. ComplexProduct      4. ComplexDivide    *****" << endl;
	cout << "*****               5. ComplexModel              *****" << endl;
	cout << "******************************************************" << endl;
	//detect what to do
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "请输入第一个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "请输入第二个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 + op2;
		
		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 2:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "请输入第一个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "请输入第二个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 - op2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 3:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "请输入第一个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "请输入第二个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 * op2;

		cout << "The answer is: ";
		cout << result << endl;

	}
	break;

	case 4:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "请输入第一个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "请输入第二个复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 / op2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 5:
	{
		Complex op1;
		double a, b;
		cout << "请输入复数的实部和虚部，中间用空格隔开： ";
		cin >> a >> b;
		op1 = Complex(a, b);


		double result;
		result = op1.model();

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	default:
		break;
	}

}

void pictureDraw()
{
	cout << "******************************************************" << endl;
	cout << "*****           你想查看哪种三角函数：           *****" << endl;
	cout << "*****	           1.余弦    2.正弦               *****" << endl;
	//cout << "**** Please choose which picture you want to draw ****" << endl;
	//cout << "***** 1.指数函数                                 *****" << endl;
	//cout << "***** 2.幂函数                                   *****" << endl;
	//cout << "***** 3.对数函数                                 *****" << endl;
	//cout << "***** 4.三角函数                                 *****" << endl;
	//cout << "***** 5.反三角函数                               *****" << endl;
	cout << "******************************************************" << endl;

	int choice;
	cin >> choice;		//choose which picture you will draw
	//int knum = 0;
	//float x, xlimit, y, ylimit;	//量程和分度值
	//float outcome;	//单次计算结果
	//string fileName;	//输出文件的名称
	//char character;

	switch (choice)
	{
	case 1:
	{
		/*
		//y=a^x（a>0且a!=1）
		float a;
		cout << "请输入底数a:";
		cin >> a;
		while (a <= 0 || a == 1)
		{
			cout << "a值不在合理范围内，请重新输入: ";
			cin >> a;
		}
		if (a > 1) fileName = "指数函数（底数 > 1）.txt";
		else fileName = "指数函数（0 < 底数 < 1）.txt";
		ifstream ifs(fileName);
		ifs >> noskipws;
		system("cls");
		while (!ifs.eof())
		{
			//用txt文件来画一个坐标轴
			ifs >> character;
			if (character == 'k')
			{
				x = 10.25 - knum * 0.25;
				knum++;
				if (x == 0)
				{
					x -= 0.25;
					knum++;
				}
				cout << setw(5) << x;
			}
			else if (character == 'c')
			{
				xlimit = log(10.25) / log(a);
				xlimit = (int)(xlimit * 100 + 0.5) / 100.00;
				cout << xlimit;
			}
			else cout << character;
			ifs.close();	//关闭文件


			if (a > 1)
			{
				for (int i = -11; i <= 100; i++)
				{
					y = pow(a, xlimit / 100 * i);
					if (y > 10.25)
					{
						outcome = 0;
					}
					else
					{
						outcome = (int)((10.25 - y) / 0.25 + 0.5);
					}
					gotoxy(i + 11, outcome);
					cout << "*";
				}
			}
			else if (a < 1 && a>0)
			{
				for (int i = 110; i >= -7; i--)
				{
					y = pow(a, xlimit / 110 * i);
					if (y > 10.25)
						outcome = 0;
					else outcome = (int)((10.25 - y) / 0.25 + 0.5);
					gotoxy(110 - i + 1, outcome);
					cout << "*";
				}
			}
			system("pause");
		}
		*/
		{//余弦
			double y;
			int x, space;
			for (y = 1; y >= -1; y -= 0.1)
			{
				space = acos(y) * 10;
				for (x = 0; x < space; x++)
				{
					cout << " ";
				}
				cout << "*";
				for (; x < 62 - space; x++)
				{
					cout << " ";
				}
				cout << "*" << endl;
			}
		}

	}
	break;

	case 2:
	{
		{//正弦
			double y;
			int x, space;
			for (y = 1; y >= -1; y -= 0.1)
			{
				space = asin(y) * 10;
				for (x = -32; x < space; x++)
				{
					cout << " ";
				}
				cout << "*";
				for (; x < 32 - space; x++)
				{
					cout << " ";
				}
				cout << "*" << endl;
			}
		}
	}
	break;

	case 3:
	{

	}
	break;

	case 4:
	{
		//cout << "你想查看哪种三角函数：" << endl;
		//cout << "1.余弦    2.正弦" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{//余弦
			double y;
			int x, space;
			for (y = 1; y >= -1; y -= 0.1)
			{
				space = acos(y) * 10;
				for (x = 0; x < space; x++)
				{
					cout << " ";
				}
				cout << "*";
				for (; x < 62 - space; x++)
				{
					cout << " ";
				}
				cout << "*" << endl;
			}
		}
		break;

		case 2:
		{//正弦
			double y;
			int x, space;
			for (y = 1; y >= -1; y -= 0.1)
			{
				space = asin(y) * 10;
				for (x = -32; x < space; x++)
				{
					cout << " ";
				}
				cout << "*";
				for (; x < 32 - space; x++)
				{
					cout << " ";
				}
				cout << "*" << endl;
			}
		}
		break;

		}
	}
	break;

	case 5:
	{
		cout << "你想查看哪种三角函数：" << endl;
		cout << "1.反余弦    2.反正弦" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{//反余弦
			double y;
			int x, space;
			for (y = 6.2; y >= 0; y -= 0.1)
			{
				space = cos(y) * 10;
				for (x = -10; x < space; x++)
				{
					cout << " ";
				}
				cout << "*";
			}
		}
		break;
		}
	}	
	break;

	default:
		break;
	}
}

void gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(hOut, c);
}

void polynomialCompute()
{
	cout << "f(x) = a0 + a1*x + a2*x*x + a3*x*x*x " << endl;
	cout << "请依次输入多项式的系数a0, a1, a2, a3: " << endl;
	double pp0;
	double pp1;
	double pp2;
	double pp3;
	cin >> pp0;
	cin >> pp1;
	cin >> pp2;
	cin >> pp3;
	Polynomial polynomial = Polynomial(pp0, pp1, pp2, pp3);
	cout << "多项式为：";
	//cout << "f(x) = " << polynomial.getA0() << " + " << polynomial.getA1() << " * x + "
	//	<< polynomial.getA2() << " * x*x + " << polynomial.getA3() << " * x*x*x ";
	cout << polynomial;
	double x;
	cout << "请输入变量x的值：";
	cin >> x;
	cout << "多项式的计算结果为：";
	polynomial.setX(x);
	cout << polynomial.computeValue();
}

void simpleCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. 加法运算              2. 减法运算       *****" << endl;
	cout << "***** 3. 乘法运算              4. 除法运算       *****" << endl;
	cout << "******************************************************" << endl;
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:
	{
		double val1, val2;
		cout << "请输入第一个数据：";
		cin >> val1;
		cout << "请输入第二个数据：";
		cin >> val2;
		double result;
		result = val1 + val2;
		cout << "计算结果是：" << result << endl;
	}
	break;

	case 2:
	{
		double val1, val2;
		cout << "请输入第一个数据：";
		cin >> val1;
		cout << "请输入第二个数据：";
		cin >> val2;
		double result;
		result = val1 - val2;
		cout << "计算结果是：" << result << endl;
	}
	break;

	case 3:
	{
		double val1, val2;
		cout << "请输入第一个数据：";
		cin >> val1;
		cout << "请输入第二个数据：";
		cin >> val2;
		double result;
		result = val1 * val2;
		cout << "计算结果是：" << result << endl;
	}
	break;

	case 4:
	{
		double val1, val2;
		cout << "请输入第一个数据：";
		cin >> val1;
		cout << "请输入第二个数据：";
		cin >> val2;
		double result;
		result = val1 / val2;
		cout << "计算结果是：" << result << endl;
	}
	break;

	default:
		break;
	}

}


void simpleFunction()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. 指数函数 x^y      2. 对数函数log(x) y   *****" << endl;
	cout << "*****                3. 三角函数                 *****" << endl;
	cout << "******************************************************" << endl;
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:
	{//指数函数 x^y
		double x;
		double y;
		cout << "请输入指数函数的底数x：";
		cin >> x;
		cout << "请输入指数y：";
		cin >> y;

		double result;
		result = pow(x, y);
		cout << "计算结果是：" << result << endl;
	}
	break;

	case 2:
	{//2. 对数函数log(x) y
		double x;
		double y;
		cout << "请输入对数函数的底数x：";
		cin >> x;
		cout << "请输入y：";
		cin >> y;

		double result;
		result = log(y) / log(x);
		cout << "计算结果是：" << result << endl;
	}
	break;

	case 3:
	{//3. 三角函数  
		cout << "******************************************************" << endl;
		cout << "****** Please choose which computation you want ******" << endl;
		cout << "***** 1. sin(x)               2. cos(x)          *****" << endl;
		cout << "*****                3. tan(x)                   *****" << endl;
		cout << "******************************************************" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{//1. sin(x)
			cout << "请输入x：";
			double x;
			cin >> x;
			double result;
			result = sin(x);
			cout << "计算结果是：" << result << endl;
		}
		break;

		case 2:
		{// 2. cos(x)
			cout << "请输入x：";
			double x;
			cin >> x;
			double result;
			result = cos(x);
			cout << "计算结果是：" << result << endl;
		}
		break;

		case 3:
		{// 3. tan(x)
			cout << "请输入x：";
			double x;
			cin >> x;
			double result;
			result = tan(x);
			cout << "计算结果是：" << result << endl;
		}
		break;

		default:
			break;
		}
	}
	break;

	default:
		break;
	}
}

void beautifulCompute()
{
	system("C:\\Users\\lenovo\\Desktop\\CPP实训\\SimpleCalculator\\SimpleCalculator.exe");
}