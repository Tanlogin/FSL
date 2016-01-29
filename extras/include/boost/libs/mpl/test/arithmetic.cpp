
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: arithmetic.cpp,v 1.1.1.2 2015/02/27 16:50:37 mwebster Exp $
// $Date: 2015/02/27 16:50:37 $
// $Revision: 1.1.1.2 $

#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef int_<0> _0;
    typedef int_<1> _1;
    typedef int_<3> _3;
    typedef int_<10> _10;

    MPL_ASSERT_RELATION( (plus<_0,_10>::value), ==, 10 );
    MPL_ASSERT_RELATION( (plus<_10,_0>::value), ==, 10 );

    MPL_ASSERT_RELATION( (minus<_0,_10>::value), ==, -10 );
    MPL_ASSERT_RELATION( (minus<_10,_0>::value), ==, 10 );

    MPL_ASSERT_RELATION( (times<_1,_10>::value), ==, 10 );
    MPL_ASSERT_RELATION( (times<_10,_1>::value), ==, 10 );
    MPL_ASSERT_RELATION( (multiplies<_1,_10>::value), ==, 10 );
    MPL_ASSERT_RELATION( (multiplies<_10,_1>::value), ==, 10 );

    MPL_ASSERT_RELATION( (divides<_10,_1>::value), ==, 10 );
    MPL_ASSERT_RELATION( (divides<_10,_1>::value), ==, 10 );

    MPL_ASSERT_RELATION( (modulus<_10,_1>::value), ==, 0 );
    MPL_ASSERT_RELATION( (modulus<_10,_3>::value), ==, 1 );

#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    MPL_ASSERT_RELATION( (minus<_10,_1,_10>::value), ==, -1 );
    MPL_ASSERT_RELATION( (plus<_10,_1,_10>::value), ==, 21 );
    MPL_ASSERT_RELATION( (divides<_10,_1,_10>::value), ==, 1 );
    MPL_ASSERT_RELATION( (divides<_10,_1,_10>::value), ==, 1 );
#endif
    
    MPL_ASSERT_RELATION( negate<_10>::value, ==, -10 );
}
