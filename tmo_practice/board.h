#include <iostream>
#include <cstring>
#include <algorithm>


#pragma once


template<typename T>
class Board
{
private:
	int mHeight = 10;
	int mWidth = 10;
	T mData;

public:
	Board();
	Board(int pHeight, int pWidth);
	~Board();
	void set_board(int pHeight, int pWidth);
	void set_data(T pData);
	T getData() const;
	int getHeight() const;
	int getWidth() const;

};

template<typename T>
inline Board<T>::Board()
{
}

template<typename T>
inline Board<T>::Board(int pHeight, int pWidth)
{
	set_board(pHeight, pWidth);
}

template<typename T>
inline Board<T>::~Board()
{

}

template<typename T>
inline void Board<T>::set_board(int pHeight, int pWidth)
{
	this->mHeight = pHeight;
	this->mWidth = pWidth;
}

template<typename T>
inline void Board<T>::set_data(T pData)
{
	this->mData = pData;
}

template<typename T>
inline T Board<T>::getData() const
{
	return this->mData;
}

template<typename T>
inline int Board<T>::getHeight() const
{
	return this->mHeight;
}

template<typename T>
inline int Board<T>::getWidth() const
{
	return this->mWidth;
}

