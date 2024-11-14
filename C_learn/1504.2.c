#include <iostream>
#include <cassert>
#include <utility>
using namespace std;
class IntArray {
	private:
		size_t arrSize;
		int *ptr;
	public:
		IntArray();//Ĭ�Ϲ��캯��
		IntArray(const IntArray & ia);//�������캯��
		IntArray(IntArray && ia)noexcept;//�ƶ����캯��
		explicit IntArray(int size);//ָ�������Сsize
		IntArray(int ia[],size_t size);//����������ia��ʼ������
		~IntArray();//��������
		IntArray& operator=(const IntArray& right);//������ֵ�����
		IntArray& operator=(IntArray&& right)noexcept;//�ƶ���ֵ�����

		int& get(size_t index);//ȡ����Ԫ�أ�������ֵ��
		const int& get(size_t index)const;// const�汾
		void set(size_t size,int a);
		size_t size()const;//���������С
};
IntArray::IntArray():arrSize(0),ptr(NULL) {}
IntArray::IntArray(const IntArray& ia):arrSize(ia.arrSize) {
	//���
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = ia.ptr[id];
}
IntArray::IntArray(IntArray&& ia)noexcept
:
arrSize(ia.arrSize),ptr(ia.ptr) { //�ƶ�
	ia.arrSize = 0;
	ia.ptr = NULL;  //���������ݵĶ�����Ϊ������
}
IntArray::IntArray(int ia[],size_t size) {
	assert(size > 0);
	arrSize = size;
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = ia[id];
}
IntArray::IntArray(int size) {
	//����ָ����С��������
	assert(size > 0);
	arrSize = size;
	ptr = new int[arrSize];
	for(size_t id = 0; id < arrSize; id++)
		ptr[id] = 0;  //������Ԫ����Ϊ0
}
IntArray::~IntArray() {
	delete [] ptr;
}
IntArray& IntArray::operator=(const IntArray& right) {
	//������ֵ
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
	//�ƶ���ֵ
	if(this == &right)
		return *this;
	arrSize = right.arrSize;
	ptr = right.ptr;//�ƶ���ֵ��ָ�븳ֵ�����踳ֵ����Ԫ��
	right.ptr = NULL;
	right.arrSize = 0;//��Ԫ�����ÿ�
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
//���Գ���
//��������С��Ԫ��ֵ 
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
	ia3.get(1) = 9;//�޸�һ��Ԫ�ص�ֵ 
	cout << "ia3 ";
	print(ia3);
	cout << "ia2 ";
	print(ia2); 
	
	cout << "ia1 = std::move(ia2)" << endl;
	ia1 = std::move(ia2);
	ia1.get(3) = 8;//�޸�һ��Ԫ�ص�ֵ 
	cout << "ia1 ";
	print(ia1);
	cout << "ia2 ";
	print(ia2); 
	
	cout << "IntArray ia4(std::move(ia1))" << endl;
	ia1.get(2) = 7;//�޸�һ��Ԫ�ص�ֵ 
	IntArray ia4(std::move(ia1));
	cout << "ia4 ";
	print(ia4);
	cout << "ia1 ";
	print(ia1); 
	return 0;
}

