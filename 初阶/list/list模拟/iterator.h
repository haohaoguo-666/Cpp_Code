#pragma once

namespace yyf
{
	template<class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		//封装了_list_iterator<T,Ref,Ptr>
		typedef ReverseIterator<Iterator, Ref, Ptr> Self;
		Iterator _cur;

        //构造
        ReverseIterator(Iterator it)
            :_cur(it)
        {}

        Ref operator*()
        {
            Iterator tmp = _cur;
            --tmp;
            return *tmp;
        }

        Ptr operator->()
        {
            return &(operator*());
        }

        Self& operator++()
        {
            --_cur;
            return *this;
        }

        Self operator++(int)
        {
            Self tmp = _cur;
            --_cur;
            return tmp;
        }

        Self& operator--()
        {
            ++_cur;
            return *this;
        }

        Self operator--(int)
        {
            Self tmp = _cur;
            ++_cur;
            return tmp;
        }

        bool operator !=(const Self& s)
        {
            return _cur != s._cur;
        }

        bool operator ==(const Self& s)
        {
            return _cur == s._cur;
        }
	};
}

