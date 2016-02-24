#ifndef INC_CAMERAFPSHOOTER_H_
#define INC_CAMERAFPSHOOTER_H_

#include "YawPitchCameraController.h"

class CCamera;

class CFPSCameraController : public IYawPitchCameraController
{
private:
	float						m_YawSpeed;
	float						m_PitchSpeed;
	float						m_Speed;
	float						m_FastSpeed;
public:
	CFPSCameraController();
	virtual ~CFPSCameraController();

	void Move(float Strafe, float Forward, bool Speed, float ElapsedTime);
	void UpdateCameraValues(CCamera *Camera) const;
	void AddYaw(float Radians);
	void AddPitch(float Radians);
	Vect3f GetDirection() const;

	void Update( float ElapsedTime );

};

#endif
