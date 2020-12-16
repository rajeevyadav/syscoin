// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SYSCOIN_SHUTDOWN_H
#define SYSCOIN_SHUTDOWN_H

/** Initialize shutdown state. This must be called before using either StartShutdown(),
 * AbortShutdown() or WaitForShutdown(). Calling ShutdownRequested() is always safe.
 */
bool InitShutdownState();

/** Request shutdown of the application. */
void StartShutdown();

/** Clear shutdown flag. Only use this during init (before calling WaitForShutdown in any
 * thread), or in the unit tests. Calling it in other circumstances will cause a race condition.
 */
void AbortShutdown();

/** Returns true if a shutdown is requested, false otherwise. */
bool ShutdownRequested();

/** Wait for StartShutdown to be called in any thread. This can only be used
 * from a single thread.
 */
void WaitForShutdown();

#endif
