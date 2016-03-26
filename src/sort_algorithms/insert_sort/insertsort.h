/*
 * Copyright 2016- huaxz <huaxz1986@163.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: huaxz1986@163.com (huaxz)
 */
#ifndef INSERTSORTE_H
#define INSERTSORTE_H

namespace IntrodunctionToAlgorithm
{

    namespace SortAlgorithm
    {
    //!insert_sort：算法导论第二章 2.1
    /*!
    * \param begin : 待排序序列的起始迭代器
    * \param end: 待排序序列的终止迭代器
    * \param compare: 一个用于排序的可调用对象，接受两个 Iterator对象，返回布尔值（若前者指向的对象小于后者指向的对象，则返回 true)
    * \return void
    *
    * - 插入排序思想，假设对数组A[p...r]排序：
    *   - 维持不变式：设当前排序的元素是 A[q]，则保持A[p...q-1]为排好的，A[q]在A[p...q-1]中找到它的位置坐下
    * - 时间复杂度 O(n^2)
    * - 原地排序
    */
    template<typename Iterator> void insert_sort(Iterator begin,Iterator end,
                                bool(*compare)(Iterator iter_little,Iterator iter_big)=
                                [](Iterator iter_little,Iterator iter_big){return *iter_little< *iter_big;})
     {
            if(end-begin<=1)
                return;
            auto current=begin;

            while(++current!=end)
            {
                auto iter=current;
                while(iter!=begin)
                {
                    if(compare(iter,iter-1)) //  前后两两比较，若后者小则交换
                    {
                        std::swap(*iter,*(iter-1));
                        iter--;
                    }else //  前后两两比较，若后者大则交换跳出
                    {
                        break;
                    }

                }
            }

        }
    }

}
#endif // INSERTSORTE_H