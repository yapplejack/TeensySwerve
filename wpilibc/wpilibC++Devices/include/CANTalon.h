/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2014. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#pragma once

#include "SafePWM.h"
#include "CANSpeedController.h"
#include "PIDOutput.h"
#include "MotorSafetyHelper.h"

class CanTalonSRX;

/**
 * CTRE Talon SRX Speed Controller
 */
class CANTalon : public MotorSafety,
                 public CANSpeedController,
                 public ErrorBase
{
public:
	explicit CANTalon(uint8_t deviceNumber);
	virtual ~CANTalon();

	// PIDController interface
	virtual void PIDWrite(float output) override;

	// MotorSafety interface
	virtual void SetExpiration(float timeout) override;
	virtual float GetExpiration() override;
	virtual bool IsAlive() override;
	virtual void StopMotor() override;
	virtual void SetSafetyEnabled(bool enabled) override;
	virtual bool IsSafetyEnabled() override;
	virtual void GetDescription(char *desc) override;

	// CANSpeedController interface
	virtual float Get() override;
	virtual void Set(float value, uint8_t syncGroup=0) override;
	virtual void Disable() override;
	virtual void SetP(double p) override;
	virtual void SetI(double i) override;
	virtual void SetD(double d) override;
	virtual void SetPID(double p, double i, double d) override;
	virtual double GetP() override;
	virtual double GetI() override;
	virtual double GetD() override;
	virtual float GetBusVoltage() override;
	virtual float GetOutputVoltage() override;
	virtual float GetOutputCurrent() override;
	virtual float GetTemperature() override;
	virtual double GetPosition() override;
	virtual double GetSpeed() override;
	virtual bool GetForwardLimitOK() override;
	virtual bool GetReverseLimitOK() override;
	virtual uint16_t GetFaults() override;
	virtual void SetVoltageRampRate(double rampRate) override;
	virtual uint32_t GetFirmwareVersion() override;
	virtual void ConfigNeutralMode(NeutralMode mode) override;
	virtual void ConfigEncoderCodesPerRev(uint16_t codesPerRev) override;
	virtual void ConfigPotentiometerTurns(uint16_t turns) override;
	virtual void ConfigSoftPositionLimits(double forwardLimitPosition, double reverseLimitPosition) override;
	virtual void DisableSoftPositionLimits() override;
	virtual void ConfigLimitMode(LimitMode mode) override;
	virtual void ConfigForwardLimit(double forwardLimitPosition) override;
	virtual void ConfigReverseLimit(double reverseLimitPosition) override;
	virtual void ConfigMaxOutputVoltage(double voltage) override;
	virtual void ConfigFaultTime(float faultTime) override;
	virtual void SetControlMode(ControlMode mode) override;
	virtual ControlMode GetControlMode() override;

private:
	uint8_t m_deviceNumber;
	CanTalonSRX *m_impl;
	MotorSafetyHelper *m_safetyHelper;
};
