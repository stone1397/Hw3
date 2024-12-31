#include <iostream>
#include <algorithm>

template<typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
		data = new T[currentCapacity];
	}

	// ���� ���� ������ �ʱ�ȭ ����Ʈ�� data�� ������ �� ����.
	SimpleVector(const SimpleVector& other) : currentCapacity(other.currentCapacity), currentSize(other.currentSize) {
		std::cout << "���� ������ ȣ��" << std::endl;

		// ���ο� �迭 ����
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
	}

	int capacity() { return currentCapacity; }

	int size() { return currentSize; }

	void pop_back()
	{
		if (currentSize != 0) {
			currentSize--;
		}
		else {
			std::cout << "������ ���Ұ� �����ϴ�" << std::endl;
		}
	}

	void push_back(const T& element)
	{
		if (currentCapacity > currentSize) {
			data[currentSize] = element;
			currentSize++;
		}
		else {
			currentCapacity += 5;
			T* newdata = new T[currentCapacity];
			
			for (int i = 0; i < currentSize; i++) {
				newdata[i] = data[i];
			}

			newdata[currentSize] = element;
			currentSize++;
			
			delete[] data;
			data = newdata;
		}
	}

	void resize(int newCapacity)
	{
		if (newCapacity > currentCapacity) {
			currentCapacity = newCapacity;
			T* newdata = new T[currentCapacity];

			for (int i = 0; i < currentSize; i++) {
				newdata[i] = data[i];
			}

			delete[] data;
			data = newdata;

		}
	}

	void sortData()
	{
		//�����Ͱ� �迭���� ���
		std::sort(data, data + currentSize);
	}

	T setter(int index)
	{
		return data[index];
	}


	~SimpleVector() {
		delete[] data;
	}
	
};

// �׽�Ʈ �ڵ�
int main() {
	SimpleVector<int> vec(3);

	vec.push_back(40);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);

	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.sortData();

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec.setter(i) << ", ";
	}
	std::cout << std::endl;


	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();


	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	
	return 0;
}