//! \brief ��������� ������������� �������.
struct DynamicArray
{
private:
	//! \brief ������ �������.
	int _size;

	//! \brief ����������� �������.
	int _capacity;

	//! \brief ������.
	int* _array;

	//! \brief ������ ����� ��� ��������� ����������� �������.
	const float _growthFactor = 2;

public:

	//! \brief ����������� ��-���������.
	DynamicArray();

	//! \brief ������������� ������
	~DynamicArray();

	//! \brief ���������� ������ �������.
	//! \return ������ �������.
	int GetSize();

	//! \brief ���������� ����������� �������.
	//! \return ����������� �������.
	int GetCapacity();

	//! \brief ���������� ������.
	//! \return ������.
	int* GetArray();

	//! \brief �������� ����������� �������.
	//! \param newCapacity ����� ����������� �������.
	void Resize(int newCapacity);

	//! \brief ��������� ������� � ������.
	//! \param index ������ ��������, ���� ����� �������� �������.
	//! \param value �������� ���������
	void AddElement(int index, int value);

	//! \brief  ������� ������� ������� �� ��������� �������.
	//! \param index ������ ���������� ��������.
	void RemoveByIndex(int index);

	//! \brief ������� �������� �������� �� ��� ������������� ��������.
	//! \param value ���������� ��������, ������� ����� �������.
	void RemoveByValue(int value);

	//! \brief ���������� ������� �� �������.
	//! \param index ������, �� �������� ����� �������� ��������.
	//! \return ���������� ��������, ������� ��������� ��� ��������.
	int GetElemnt(int index);

	//! \brief ��������� ������.
	void SortArray();

	//! \brief ��������� ������ �������.
	void SelectionSort();

	//! \brief �������� ����� ������� �������� �� ������������� ��������.
	//! \param value ��������, ������ �������� ����� �����.
	void LinerSearch(int value);

	//! \brief �������� ����� ������� �������� �� ������������� ��������.
	//! \param value ��������, ������ �������� ����� �����.
	void BinarySearch(int value);
};