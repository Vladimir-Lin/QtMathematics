/****************************************************************************
 *                                                                          *
 * Copyright (C) 2001 ~ 2016 Neutrino International Inc.                    *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_MATHEMATICS_H
#define QT_MATHEMATICS_H

#include <QtCore>

#ifdef QT_QTCUDA_LIB
#include <QtCUDA>
#endif

#ifdef QT_ESSENTIALS_LIB
#include <Essentials>
#endif

#ifdef QT_QTGMP_LIB
#include <QtGMP>
#endif

#ifdef QT_QTGSL_LIB
#include <QtGSL>
#endif

#ifdef QT_QTALGEBRA_LIB
#include <QtAlgebra>
#endif

#ifdef QT_QTDISCRETE_LIB
#include <QtDiscrete>
#endif

#ifdef QT_QTFFT_LIB
#include <QtFFT>
#endif

#ifdef QT_QTDAI_LIB
#include <QtDAI>
#endif

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_MATHEMATICS_LIB)
#      define Q_MATHEMATICS_EXPORT Q_DECL_EXPORT
#    else
#      define Q_MATHEMATICS_EXPORT Q_DECL_IMPORT
#    endif
#else
#      define Q_MATHEMATICS_EXPORT
#endif

#define VerySmall 0.000000000000000000000000000000000000000000001

namespace N
{

class Q_MATHEMATICS_EXPORT BlobAcceptor ;
class Q_MATHEMATICS_EXPORT SyncAcceptor ;

namespace Math
{

Q_MATHEMATICS_EXPORT bool   Initialize  (void) ;
Q_MATHEMATICS_EXPORT double Radian      (double angle ) ;
Q_MATHEMATICS_EXPORT double Degree      (double radian) ;
Q_MATHEMATICS_EXPORT double fastSine    (double angle ) ;
Q_MATHEMATICS_EXPORT double fastCosine  (double angle ) ;
Q_MATHEMATICS_EXPORT int    compare     (double x, double y, double epsilon = 0.00000001) ;
Q_MATHEMATICS_EXPORT double fastCos     (int id) ;
Q_MATHEMATICS_EXPORT double fastSin     (int id) ;
Q_MATHEMATICS_EXPORT double safeFastCos (int id) ;
Q_MATHEMATICS_EXPORT double safeFastSin (int id) ;

}

/*****************************************************************************
 *                                                                           *
 *                               Data Operators                              *
 *                                                                           *
 *****************************************************************************/

class Q_MATHEMATICS_EXPORT BlobAcceptor
{
  public:

    explicit BlobAcceptor (void) ;
    virtual ~BlobAcceptor (void) ;

    virtual int  EatType  (void) const { return 0 ; }

    virtual bool Demolish (void) = 0 ;
    virtual bool Feeding  (QByteArray & data) = 0 ;

  protected:

  private:

};

class Q_MATHEMATICS_EXPORT SyncAcceptor
{
  public:

    explicit SyncAcceptor (void) ;
    virtual ~SyncAcceptor (void) ;

    virtual int  SyncType (void) const { return 0 ; }

    virtual bool Demolish (void) = 0 ;
    virtual bool Sync     (void * data) = 0 ;

  protected:

  private:

};

}

Q_DECLARE_INTERFACE(N::BlobAcceptor , "com.neutrino.math.blob.acceptor" )
Q_DECLARE_INTERFACE(N::SyncAcceptor , "com.neutrino.math.sync.acceptor" )

QT_END_NAMESPACE

#endif
