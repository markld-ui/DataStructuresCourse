//! \brief Структура динамического массива.
struct DynamicArray
{
private:
	//! \brief Размер массива.
	int _size;

	//! \brief Вместимость массива.
	int _capacity;

	//! \brief Массив.
	int* _array;

	//! \brief Фактор роста для изменения вместимости массива.
	const float _growthFactor = 2;

public:

	//! \brief Конструктор по-умолчанию.
	DynamicArray();

	//! \brief Деконструктор класса
	~DynamicArray();

	//! \brief Возвращает размер массива.
	//! \return размер массива.
	int GetSize();

	//! \brief Возвращает вместимость массива.
	//! \return Вместимость массива.
	int GetCapacity();

	//! \brief Возвращает массив.
	//! \return Массив.
	int* GetArray();

	//! \brief Изменяет размерность массива.
	//! \param newCapacity Новая размерность массива.
	void Resize(int newCapacity);

	//! \brief Добавляет элемент в массив.
	//! \param index Индекс элемента, куда нужно добавить элемент.
	//! \param value Значение элементаю
	void AddElement(int index, int value);

	//! \brief  Удаляет элемент массива по указаному индексу.
	//! \param index Индекс удаляемого элемента.
	void RemoveByIndex(int index);

	//! \brief Удаляет значение элемента по его передаваемому значению.
	//! \param value Посылаемое значение, которое нужно удалить.
	void RemoveByValue(int value);

	//! \brief Возвращает элемент по индексу.
	//! \param index Индекс, по которому нужно получить значение.
	//! \return Возвращает значение, которое находится под индексом.
	int GetElemnt(int index);

	//! \brief Сортирует массив.
	void SortArray();

	//! \brief Сортирует массив выбором.
	void SelectionSort();

	//! \brief линейный поиск индекса элемента по передаваемому значению.
	//! \param value Значение, индекс которого нужно найти.
	void LinerSearch(int value);

	//! \brief бинарный поиск индекса элемента по передаваемому значению.
	//! \param value Значение, индекс которого нужно найти.
	void BinarySearch(int value);
};