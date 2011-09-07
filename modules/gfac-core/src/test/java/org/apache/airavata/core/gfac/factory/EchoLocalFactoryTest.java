/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

package org.apache.airavata.core.gfac.factory;

import org.apache.airavata.commons.gfac.type.parameter.AbstractParameter;
import org.apache.airavata.commons.gfac.type.parameter.StringParameter;
import org.apache.airavata.core.gfac.context.invocation.impl.DefaultExecutionContext;
import org.apache.airavata.core.gfac.context.invocation.impl.DefaultInvocationContext;
import org.apache.airavata.core.gfac.context.message.impl.ParameterContextImpl;
import org.apache.airavata.core.gfac.exception.GfacException;
import org.apache.airavata.core.gfac.notification.impl.StandardOutNotification;
import org.apache.airavata.core.gfac.services.GenericService;
import org.junit.Assert;
import org.junit.Test;

public class EchoLocalFactoryTest {

	@Test
	public void testEchoLocal() {
		DefaultInvocationContext ct = new DefaultInvocationContext();

		/*
		 * Input
		 */
		ParameterContextImpl input = new ParameterContextImpl();
		StringParameter z = new StringParameter();
		z.parseStringVal("echo_output=hello");
		input.add("echo_input", z);

		/*
		 * Output
		 */
		ParameterContextImpl output = new ParameterContextImpl();
		StringParameter b = new StringParameter();
		output.add("echo_output", b);

		ct.addMessageContext("input", input);
		ct.addMessageContext("output", output);	
		
		DefaultExecutionContext x  = new DefaultExecutionContext();
		x.setNotificationService(new StandardOutNotification());
		ct.setExecutionContext(x);
		

		try {
			GenericService service = new EchoLocalServiceFactory()
					.createService();

			service.execute(ct);
		} catch (GfacException g) {
			g.printStackTrace();
		}

		Assert.assertNotNull(ct.getMessageContext("output"));
		Assert.assertNotNull(ct.getMessageContext("output").getValue(
				"echo_output"));
		Assert.assertEquals("hello", ct.<AbstractParameter>getMessageContext("output").getValue("echo_output")
				.toStringVal());
	}

	@Test
	public void testGetGenericService() {
	}

	@Test
	public void testCreateService() {
	}

}
