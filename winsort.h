//���ߣ�Winsir
//ʱ�䣺2016/3/20
//˵���������㷨���ڿ�������

template <class T>
void winsort(T *array, size_t p, size_t q)
{
    if(p <= q)
    {
        winpartion(array, p, q);
    }
}

/*
�������еĺ������ǻ��� < ���ŵıȽ�
�Զ�������ݽṹ���� < ����������
*/
template<class T>
bool operator < (T t1, T t2)
{
    return t1 < t2;
}

template <class T>
void winpartion(T *array, int r, int q)
{
    if(r < q)
    {
        T temp = array[r];
        int i = r;
        int j = q;
        while(i < j)
        {
            while(i < j && temp < array[j])
                --j;

            if(i < j)
            {
                winswap(array[i], array[j]);
                i++;
            }

            while(i < j && array[i] < temp)
                ++i;

            if(i < j)
            {
                winswap(array[i], array[j]);
                j--;
            }
        }
        winpartion(array, r, i - 1);
        winpartion(array, i + 1, q);
    }
}
  
template <class T>
void winswap(T &a1, T &a2)
{
    T tmp = a1;
    a1 = a2;
    a2 = tmp;
}
