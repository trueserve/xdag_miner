/*
    This file is part of cpp-ethereum.

    cpp-ethereum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cpp-ethereum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Common.h
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 *
 * Very common stuff (i.e. that every other header needs except vector_ref.h).
 */

#pragma once

 // way to many unsigned to size_t warnings in 32 bit build
#ifdef _M_IX86
#pragma warning(disable:4244)
#endif

#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_set>
#include <functional>
#include <string>
#include <chrono>
#include <boost/functional/hash.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include "vector_ref.h"

using byte = uint8_t;

namespace XDag
{
    // Binary data types.
    using bytes = std::vector<byte>;
    using bytesRef = vector_ref<byte>;
    using bytesConstRef = vector_ref<byte const>;

    // Numeric types.
    using bigint = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<>>;
    using u64 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<64, 64, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
    using u128 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<128, 128, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
    using u256 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
    using s256 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void>>;
    using u160 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<160, 160, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
    using s160 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<160, 160, boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void>>;
    using u512 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
    using u256s = std::vector<u256>;
    using u160s = std::vector<u160>;
    using u256Set = std::set<u256>;
    using u160Set = std::set<u160>;

    // String types.
    using strings = std::vector<std::string>;

    // Null/Invalid values for convenience.
    static const u256 Invalid256 = ~(u256)0;

    /// Converts arbitrary value to string representation using std::stringstream.
    template <class _T>
    std::string ToString(_T const& _t)
    {
        std::ostringstream o;
        o << _t;
        return o.str();
    }
}
