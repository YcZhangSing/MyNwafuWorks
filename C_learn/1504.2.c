#include <iostream>
#include <cassert>
#include <utility>
using namespace std;
class IntArray {
	private:
		size_t arrSize;
		int *ptr;
	public:
		IntArray();//默认构造函数
		IntArray(const IntArray & ia);//拷贝构造函数
		IntArray(IntArray && ia)noexcept;//移动构造函数
		explicit IntArray(int size);//指定数组大小size
		IntArray(int ia[],size_t size);//用内置数组ia初始化对象
		~IntArray();//析构函数
		IntArray& operator=(const IntArray& right);//拷贝赋值运算符
		IntArray& operator=(IntArray&& right)noexcept;//移动赋值运算符

		int& get(size_t index);//取数组元素，返回左值；
		const int& get(size_t index)const;// const版本
		void set(size_t size,int a);
		size_t size()const;//返回数组大小
};
IntArray::IntArray():arrSize(0),ptr(NULL) {}
IntArray::IntArray(const IntArray& ia):arrSize(ia.arrSize) {
	//深复制
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = ia.ptr[id];
}
IntArray::IntArray(IntArray&& ia)noexcept
:
arrSize(ia.arrSize),ptr(ia.ptr) { //移动
	ia.arrSize = 0;
	ia.ptr = NULL;  //被移走数据的对象置为空数组
}
IntArray::IntArray(int ia[],size_t size) {
	assert(size > 0);
	arrSize = size;
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = ia[id];
}
IntArray::IntArray(int size) {
	//按照指定大小创建数组
	assert(size > 0);
	arrSize = size;
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = 0;  //将数组元素置为0
}
IntArray::~IntArray() {
	delete [] ptr;
}
IntArray& IntArray::operator=(const IntArray& right) {
	//拷贝赋值
	if(this == &right)
		return *this;
	arrSize = right.arrSize;
	delete [] ptr;
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = right.ptr[id];
	return *this;
}
IntArray& IntArray::operator=(IntArray&& right)noexcept {
	//移动赋值
	if(this == &right)
		return *this;
	arrSize = right.arrSize;
	ptr = right.ptr;//移动赋值，指针赋值，无需赋值数组元素
	right.ptr = NULL;
	right.arrSize = 0;//将元对象置空
	return *this;
}
int& IntArray::get(size_t index) {
	assert(index >= 0 && index < arrSize);
	return ptr[index];
}
const int& IntArray::get(size_t index)const {
	assert(index >= 0 && index < arrSize);
	return ptr[index];
}
size_t IntArray::size()const {
	return arrSize;
}
void IntArray::set(size_t size,int a)
{
	assert(size >= 0 && size < arrSize);
	ptr[size] = a;
}
void print(const IntArray& ia)
{
	cout << ia.size() << "elements: ";
	for(size_t id = 0; id < ia.size(); id++)
		cout << ia.get(id) << " ";
	cout << endl;
		
}
//测试程序
//输出数组大小和元素值 
int main()
{
	int a[] = {1,2,3,4,5};
	
	cout << "IntArray ia1" << endl;
	IntArray ia1;
	cout << "ia1 ";
	print(ia1);
	
	cout << "IntArray ia2(a,5)" << endl;
	IntArray ia2(a,5);
	a[2] = 6;
	cout << "ia2 ";
	print(ia2);
	
	cout << "IntArray ia3 = ia2" << endl;
	IntArray ia3 = ia2;
	ia3.get(1) = 9;//修改一个元素的值 
	cout << "ia3 ";
	print(ia3);
	cout << "ia2 ";
	print(ia2); 
	
	cout << "ia1 = std::move(ia2)" << endl;
	ia1 = std::move(ia2);
	ia1.get(3) = 8;//修改一个元素的值 
	cout << "ia1 ";
	print(ia1);
	cout << "ia2 ";
	print(ia2); 
	
	cout << "IntArray ia4(std::move(ia1))" << endl;
	ia1.get(2) = 7;//修改一个元素的值 
	IntArray ia4(std::move(ia1));
	cout << "ia4 ";
	print(ia4);
	cout << "ia1 ";
	print(ia1); 
	return 0;
}

