// Copyright (c) 2014-2015 The AsturCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ASTURCOINADDRESSVALIDATOR_H
#define ASTURCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AsturCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AsturCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** AsturCoin address widget validator, checks for a valid asturcoin address.
 */
class AsturCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AsturCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ASTURCOINADDRESSVALIDATOR_H
